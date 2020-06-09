import java.util.LinkedList;
public class basic{

	public static void main( String[] args) {
        solve();
    }

    public static void fibonacci() {
         int n = 10; // nth term in fibonacci
        System.out.println(fib_01(n)); // simple recursion
        System.out.println(fib_02(n)); // simple for loop (most accurate and fast always prefer this)
         int[] dp = new int[n + 1];
        System.out.println(fib_03(n, dp)); // using memoization

         int[][] a = { { 1, 1 }, { 1, 0 } };
         int[][] ans = fib_04(n, a); // matrix multiplication
        System.out.println(ans[0][1]);
        display_2D(ans);
    }

    public static int fib_01( int n) {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        return fib_01(n - 1) + fib_01(n - 2);
    }

    public static int fib_02( int n) {
        int a = 1;
        int b = 1;
        int c = b + a;
        for (int i = 3; i <= n; i++) {
            c = b + a;
            a = b;
            b = c;
        }

        // dp using tabulation
         int[] dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = dp[2] = 1;
        for (int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }

    public static int fib_03( int n,  int[] dp) {
        if (n == 0)
            return dp[0] = 0;
        if (n == 1 || n == 2)
            return dp[n] = 1;
        if (dp[n] != 0)
            return dp[n];
        return dp[n] = fib_03(n - 1, dp) + fib_03(n - 2, dp);
    }

    public static void display_2D( int[][] a) {
         int n = a.length;
         int m = a[0].length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                System.out.print(a[i][j] + " ");

            System.out.println();
        }
    }

    public static int[][] multiply( int[][] a,  int[][] b) {
         int a0 = a[0][0] * b[0][0] + a[0][1] * b[1][0];
         int a1 = a[0][0] * b[0][1] + a[0][1] * b[1][1];
         int a2 = a[1][0] * b[0][0] + a[1][1] * b[1][0];
         int a3 = a[1][0] * b[0][1] + a[1][1] * b[1][1];
         int[][] ans = new int[2][2];
        ans[0][0] = a0;
        ans[0][1] = a1;
        ans[1][0] = a2;
        ans[1][1] = a3;
        return ans;
    }

    public static int[][] fib_04( int n,  int[][] a) {
        if (n == 1)
            return a;
         int[][] left = fib_04(n / 2, a);
         int[][] ans = multiply(left, left);
        if (n % 2 == 0)
            return ans;

        return multiply(ans, a);
    }

    // ======================================================================================================================

    public static void mazepath() {
        // call in three directions
         int[][] dir = { { 0, 1 }, { 1, 0 }, { 1, 1 } };
         int[][] dp = new int[4][4];
        System.out.println("mazepath: ");
        System.out.println(path_01(0, 0, 4, 4, dp)); // simple recursion using memoisation
        System.out.println(path_02(4, 4)); // using dp

        // unique path
         int[][] grid = { { 1, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 2, -1 } };
        System.out.println(uniquePathsIII(grid));

        // board path multi move i.e including jumps
        System.out.println(path_jump(0, 0, 4, 4));

        System.out.println(path_jump_dp(0, 0, 4, 4));

    }

    public static int path_01( int sr,  int sc,  int er,  int ec,  int[][] dp) {
        if (sr == er - 1 && sc == ec - 1)
            return dp[sr][sc] = 1;

        if (dp[sr][sc] != 0)
            return dp[sr][sc];
        int count = 0;
        if (sr + 1 < er)
            count += path_01(sr + 1, sc, er, ec, dp);
        if (sc + 1 < ec)
            count += path_01(sr, sc + 1, er, ec, dp);
        if (sr + 1 < er && sc + 1 < ec)
            count += path_01(sr + 1, sc + 1, er, ec, dp);

        return dp[sr][sc] = count;

    }

    public static int path_02( int er,  int ec) {
         int[][] dp = new int[er][ec];
        for (int i = er - 1; i >= 0; i--) {
            for (int j = ec - 1; j >= 0; j--) {
                if (i == er - 1 && j == ec - 1) {
                    dp[i][j] = 1;
                    continue;
                }
                int count = 0;
                if (i + 1 < er)
                    count += dp[i + 1][j];
                if (j + 1 < ec)
                    count += dp[i][j + 1];
                if (i + 1 < er && j + 1 < ec)
                    count += dp[i + 1][j + 1];

                dp[i][j] = count;

            }
        }

        return dp[0][0];
    }

    // unique path 2 : leetcode

    // unique path 3:leetcode 980
    static int[][] dir = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

    public static int find_path( int[][] grid,  int sr,  int sc,  int er,  int ec,
             int count) {
        if (sr == er && sc == ec && grid[sr][sc] == 2) {
            return count == 1 ? 1 : 0;
        }
        int ans = 0;
        if (grid[sr][sc] == -1)
            return 0;
         int no = grid[sr][sc];
        grid[sr][sc] = -1;
        for (int i = 0; i < 4; i++) {
             int r = sr + dir[i][0];
             int c = sc + dir[i][1];
             int n = grid.length;
             int m = grid[0].length;
            if (r >= 0 && c >= 0 && r < n && c < m && grid[r][c] != -1) {
                ans += find_path(grid, r, c, er, ec, count - 1);
            }
        }
        grid[sr][sc] = no;
        return ans;
    }

    public static int uniquePathsIII( int[][] grid) {
         int n = grid.length;
         int m = grid[0].length;

        int count = 0;
        int sr = 0, sc = 0, er = 0, ec = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != -1)
                    count++;
                if (grid[i][j] == 1) {
                    sr = i;
                    sc = j;
                }
                if (grid[i][j] == 2) {
                    er = i;
                    ec = j;
                }
            }
        }

        return find_path(grid, sr, sc, er, ec, count);
    }

    // path using jumps
    public static int path_jump( int sr,  int sc,  int er,  int ec) {
        if (sr == er - 1 && sc == ec - 1) {
            return 1;
        }

        int count = 0;
        for (int jump = 1; jump + sr < er; jump++) {
            count += path_jump(sr + jump, sc, er, ec);
        }

        for (int jump = 1; jump + sc < ec; jump++) {
            count += path_jump(sr, sc + 1, er, ec);
        }
        for (int jump = 1; sr + jump < er && sc + jump < ec; jump++) {
            count += path_jump(sr + 1, sc + 1, er, ec);
        }

        return count;

    }

    public static int path_jump_dp( int sr,  int sc,  int er,  int ec) {
         int[][] dp = new int[er][ec];
        for (int i = er - 1; i >= 0; i--) {
            for (int j = ec - 1; j >= 0; j--) {
                if (i == er - 1 && j == ec - 1) {
                    dp[i][j] = 1;
                    continue;
                }
                int count = 0;
                for (int jump = 1; jump + i < er; jump++) {
                    count += dp[i + jump][j];
                }

                for (int jump = 1; jump + j < ec; jump++) {
                    count += dp[i][j + jump];
                }
                for (int jump = 1; i + jump < er && j + jump < ec; jump++) {
                    count += dp[i + jump][j + jump];
                }

                dp[i][j] = count;
            }
        }

        return dp[0][0];
    }

    // =================================================================================================================

    public static void dice() {
         int target = 10;
         int[] dices = { 1, 2, 3, 4, 5, 6 };
         int[] dp = new int[target + 1];
        System.out.println(find_ways_permutation(target, dices, dp));// using recursion find no of ways in which we can
                                                                     // reach target (permutation)
        // System.out.println(find_ways_combinations(target,dices));
        display_1D(dp);
        System.out.println();
        System.out.println(find_ways_dp(target, dices)); // finding no of ways using dp

        System.out.println(find_ways_optimization(target, dices));

        // the approach is simial to ways permutation just that the repeatition of same
        // number will be upto dice
        System.out.println(numRollsToTarget(10, 30, 200));
    }

    public static void display_1D( int[] dp) {
        System.out.println();
        for (int i = 0; i < dp.length; i++) {
            System.out.print(dp[i] + ", ");
        }
    }

    public static int find_ways_permutation( int target,  int[] dices,  int[] dp) {
        if (target == 0)
            return dp[target] = 1;
        int count = 0;
        if (dp[target] != 0)
            return dp[target];
        for (int i = 0; i < dices.length; i++) {
            if (target - dices[i] >= 0)
                count += find_ways_permutation(target - dices[i], dices, dp);
        }
        return dp[target] = count;
    }

    public static int find_ways_dp( int target,  int[] dices) {
        // bottom up dp
         int[] dp = new int[target + 1];
        // dp[target]=1;
        // for(int i=target-1;i>=0;i--)
        // {
        // for(int coins:dices){
        // if(i+coins<=target)
        // dp[i]+=dp[i+coins];
        // }
        // }
        // return dp[0];

        // top down dp
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for ( int coins : dices) {
                if (i - coins >= 0)
                    dp[i] += dp[i - coins];
            }
        }
        return dp[target];
    }

    // this method is only possible because the inputs the continous and only upto
    // six
    public static int find_ways_optimization( int target,  int[] dices) {
         LinkedList<Integer> link = new LinkedList<>();

        for (int i = 0; i <= target; i++) {
            if (i < 2)
                link.addFirst(1);
            if (i > 6) {
                 int lastvalue = link.removeLast();
                link.addFirst(2 * link.getFirst() - lastvalue);
            }

            else if (i >= 2 && i <= 6)
                link.addFirst(2 * link.getFirst());
        }

        System.out.println(link);
        return link.getFirst();
    }

    // leetcode 1155 : Number of dice rolls with target sum
    static double mod = (1000000000 + 7);

    // in java use double instead of long as we can not directly int to long but can
    // do that with double
    public static double find_numRollsToTarget( int dice,  int no,  int target,  double[][] dp) {
        if (target == 0) {
            int i = 1;
            if (dice == 0)
                return dp[target][dice] = 1;
            i = 0;
            if (dice > 0)
                return dp[target][dice] = 0;
            else
                return 0;
        }
        if (dice <= 0 || target > dice * no)
            return 0;

        if (dp[target][dice] != 0)
            return dp[target][dice] % mod;
        double count = 0L;
        for (int i = 1; i <= no; i++) {
            if (target - i >= 0)
                count += find_numRollsToTarget(dice - 1, no, target - i, dp);
        }
        count = count % mod;
        return dp[target][dice] = count;
    }

    public static int numRollsToTarget( int d,  int f,  int target) {
        if (d == 0)
            return 0;
        if (d == 1 && target > f)
            return 0;
        if (d == 1 && target <= f)
            return 1;
         double[][] dp = new double[target + 1][d + 1];
        find_numRollsToTarget(d, f, target, dp);

        return (int) (dp[target][d] % mod); // typecasting from double to int

    }

    // ==================================================================================================================

    public static void climb_stairs() {
        // leetcode 70,746
         int[] cost = { 1, 100, 1, 1, 100, 11, 1, 1, 100, 1 };
        System.out.println(minCostClimbingStairs_fast(cost));
        System.out.println(minCostClimbingStairs_dp(cost));

    }

    public static int minCostClimbingStairs_fast( int[] cost) {
        int a = cost[0];
        int b = cost[1];
        int c = 0;
         int n = cost.length;
        for (int i = 2; i < n; i++) {
            c = cost[i] + Math.min(a, b);
            a = b;
            b = c;
        }
        return Math.min(a, b);
    }

    public static int minCostClimbingStairs_dp( int[] cost) {
         int n = cost.length;
        if (n == 0)
            return 0;
        if (n == 1)
            return cost[0];
        if (n == 2)
            return Math.min(cost[0], cost[1]);
         int[] dp = new int[n];
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++) {
            dp[i] = cost[i] + Math.min(dp[i - 1], dp[i - 2]);

        }
        return Math.min(dp[n - 2], dp[n - 1]);
    }

    // =================================================================================================================
    public static int min_pathsum( int s,  int e,  int n,  int m,  int[][] grid,
             int[][] dp) // leetcode 64
    {
        if (s == n && e == m) {
            return dp[s][e] = grid[s][e];
        }
        if (dp[s][e] != 0)
            return dp[s][e];

        int right = Integer.MAX_VALUE;
        int down = Integer.MAX_VALUE;
        if (s + 1 <= n)
            down = min_pathsum(s + 1, e, n, m, grid, dp);
        if (e + 1 <= m)
            right = min_pathsum(s, e + 1, n, m, grid, dp);
        return dp[s][e] = grid[s][e] + Math.min(down, right);

    }

    public static int minPathSum( int[][] grid) {
         int n = grid.length;
         int m = grid[0].length;
         int[][] dp = new int[n][m];
        min_pathsum(0, 0, n - 1, m - 1, grid, dp);
        return dp[0][0];
    }

    public static int minPathSum_dp( int[][] grid) {
         int n = grid.length;
         int m = grid[0].length;
         int[][] dp = new int[n][m];

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i == n - 1 && j == m - 1) {
                    dp[i][j] = grid[i][j];
                    continue;
                }

                int ans = (int) 1e7;
                if (i + 1 < n)
                    ans = Math.min(ans, dp[i + 1][j]);
                if (j + 1 < m)
                    ans = Math.min(ans, dp[i][j + 1]);
                dp[i][j] = grid[i][j] + ans;

            }
        }
        return dp[0][0];
    }

    public static void mincostpath() {
         int[][] grid = { { 1, 3, 1 }, { 1, 5, 1 }, { 4, 2, 1 } };
        minPathSum(grid);
        System.out.println(minPathSum_dp(grid));
    }

    // ===================================================================================================================================4
    public static int goldmine_dp( int[][] grid) {
         int n = grid.length;
         int m = grid[0].length;
         int[][] dp = new int[n][m];

        for (int j = m - 1; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                if (j == m - 1) {
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int ans = Integer.MIN_VALUE;
                if (i - 1 >= 0 && j + 1 < m)
                    ans = Math.max(ans, dp[i - 1][j + 1]);
                if (i + 1 < n && j + 1 < m)
                    ans = Math.max(ans, dp[i + 1][j + 1]);
                if (j + 1 < m)
                    ans = Math.max(ans, dp[i][j + 1]);
                dp[i][j] = ans + grid[i][j];
            }
        }
        int max_ans = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++)
            max_ans = Math.max(max_ans, dp[i][0]);

        return max_ans;

    }

    public static int goldmine_rec( int[][] grid,  int[][] dp,  int sr,  int sc,  int n,
             int m) {
        if (sc == m) {
            return dp[sr][sc] = grid[sr][sc];
        }
        if (dp[sr][sc] != 0)
            return dp[sr][sc];
        int ans = Integer.MIN_VALUE;
        if (sr - 1 >= 0 && sc + 1 <= m)
            ans = Math.max(ans, goldmine_rec(grid, dp, sr - 1, sc + 1, n, m));
        if (sr + 1 <= n && sc + 1 <= m)
            ans = Math.max(ans, goldmine_rec(grid, dp, sr + 1, sc + 1, n, m));
        if (sc + 1 <= m)
            ans = Math.max(ans, goldmine_rec(grid, dp, sr, sc + 1, n, m));

        return dp[sr][sc] = ans + grid[sr][sc];
    }

    public static void goldmine() {
         int[][] grid = { { 77, 15, 93, 35 }, { 86, 92, 49, 21 }, { 62, 27, 90, 59 }, { 63, 26, 40, 26 },
                { 72, 36, 11, 68 }, { 67, 29, 82, 30 }, { 62, 23, 67, 35 } };
        System.out.println(goldmine_dp(grid));
         int n = 7;
         int m = 4;
         int[][] dp = new int[n][m];
        int ans = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            goldmine_rec(grid, dp, i, 0, n - 1, m - 1);
            ans = Math.max(ans, dp[i][0]);
        }
        System.out.println(ans);

    }

    // ==========================================================================================================================================================

    public static int pair_peope_rec( int n) {
        if (n == 1 || n == 2)
            return n;

        if (n == 0)
            return 0;

        return pair_peope_rec(n - 1) + (n - 1) * pair_peope_rec(n - 2);
    }

    public static int pair_peope_dp_memo( int n,  int[] dp) {

        if (n <= 1)
            return dp[n] = 1;
        if (dp[n] != 0)
            return dp[n];
        return dp[n] = pair_peope_dp_memo(n - 1, dp) + (n - 1) * pair_peope_dp_memo(n - 2, dp);
    }

    public static int pair_peope_dp( int n) {
         int[] dp = new int[n + 1];

        for (int i = 0; i <= n; i++) {
            if (i <= 1) {
                dp[i] = 1;
                continue;
            }
            dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
        }
        return dp[n];
    }

    public static int pair_people_fast( int n) {
        int a = 1;
        int b = 2;
        int c = 0;
        for (int i = 3; i <= n; i++) {
            c = b + (i - 1) * a;
            a = b;
            b = c;
        }

        return c;
    }

    public static void pair_and_single() {
         int n = 10;
        System.out.println(pair_peope_rec(n));
         int[] dp = new int[n + 1];
        System.out.println(pair_peope_dp_memo(n, dp));
        System.out.println(pair_peope_dp(n));
        System.out.println(pair_people_fast(n));

    }

    public static int divide_memo( int n,  int k,  int[][] dp) {
        if (k < 0)
            return 0;
        if (k == 1 || (n == k))
            return dp[n][k] = 1;
        if (k > n)
            return dp[n][k] = 0;
        return dp[n][k] = divide_memo(n - 1, k - 1, dp) + divide_memo(n - 1, k, dp) * k;
    }

    public static int divide_dp( int n,  int k) {
         int[][] dp = new int[n + 1][k + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                if (j > i)
                    continue;
                if (i == j) {
                    dp[i][j] = 1;
                    continue;
                }

                if (j == 1) {
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] * j;
            }
        }
        return dp[n][k];
    }

    public static void divide_in_kgroups() {
         int n = 8;
         int k = 3;
         int[][] dp = new int[n + 1][k + 1];
        System.out.println(divide_memo(n, k, dp));
        System.out.println(divide_dp(n, k));
        // display_2D(dp);
    }

    // ==========================================================================================================================================

    public static int jump_game_rec( int[] nums,  int start,  int n,  int ans) {
        if (start == n) {
            return ans;
        }
        int ans1 = Integer.MAX_VALUE;
         int no = nums[start];
        for (int i = 1; i <= no; i++) {
            if (start + i <= n)
                ans1 = Math.min(ans1, jump_game_rec(nums, start + i, n, ans + 1));
        }

        return ans1;
    }

    public static int jump_game_dp( int[] nums) {
         int n = nums.length;
         int[] dp = new int[n];
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                dp[0] = 0;
                continue;
            }
            dp[i] = Integer.MAX_VALUE;
            for (int j = 0; j < i; j++) {
                if (j + nums[j] >= i && dp[j] != Integer.MAX_VALUE)
                    dp[i] = Math.min(dp[i], dp[j] + 1);
            }
        }
        return dp[n - 1];
    }

    public static Boolean jump_game_simple( int[] nums) {
         int n = nums.length;
        int last = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (i + nums[i] >= last)
                last = i;
        }
        return last == 0;
    }

    public static int jump_game_optimise( int[] nums) {
         int n = nums.length;
         int[] dp = new int[n];
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            dp[i] = (int) 1e7;
            for (int j = 1; j <= nums[i]; j++) {
                if (i + j < n && dp[i + j] != (int) 1e7)
                    dp[i] = Math.min(dp[i], dp[i + j] + 1);
            }
        }
        return dp[0];

    }

    public static int jump_game_fast( int[] nums) {

         int n = nums.length;
        if (n == 0)
            return 0;
        if (n == 1 || nums[0] == 0)
            return 0;

        int max_jump = nums[0];
        int current = nums[0];
        int jump = 1;
        for (int i = 1; i < n; i++) {
            if (i == n - 1)
                return jump;
            max_jump = Math.max(max_jump, i + nums[i]);
            current--;
            if (current == 0) {
                jump++;
                current = max_jump - i;
            }
        }
        return jump;
    }

    public static void jump_game() {
         int[] nums = { 2, 3, 1, 1, 4, 3, 4, 5, 6, 7, 8, 9, 10 };
        System.out.println("O(n) ans: " + jump_game_simple(nums)); // O(n) time and O(1) space
        System.out.println("ans from rec: " + jump_game_rec(nums, 0, nums.length - 1, 0));// O(n^2);
        System.out.println("ans from dp: " + jump_game_dp(nums));

        System.out.println("ans through optimisation: " + jump_game_optimise(nums));
        System.out.println("ans in O(n): " + jump_game_fast(nums));
    }

    // =====================================================================================================================================

    public static int tri_path_rec( int[][] nums,  int[][] dp,  int row,  int column) {
        if (row == nums.length - 1)
            return dp[row][column] = nums[row][column];
        if (dp[row][column] != 0)
            return dp[row][column];

        int left = 0, right = 0;
        left = tri_path_rec(nums, dp, row + 1, column);
        right = tri_path_rec(nums, dp, row + 1, column + 1);
        return dp[row][column] = Math.min(left, right) + nums[row][column];
    }

    public static int tri_path_dp( int[][] triangle) {
         int n = triangle.length;
         int m = triangle[n - 1].length;
         int[][] dp = new int[n][m];
        for (int i = n - 1; i >= 0; i--) {
            for (int j = triangle[i].length - 1; j >= 0; j--) {
                if (i == n - 1) {
                    dp[i][j] = triangle[i][j];
                    continue;
                }
                int left = 0, right = 0;
                if (i + 1 < n)
                    left = dp[i + 1][j];
                if (i + 1 < n && j + 1 < m)
                    right = dp[i + 1][j + 1];

                dp[i][j] = Math.min(left, right) + triangle[i][j];
            }
        }
        return dp[0][0];
    }

    public static void triangle_path() {
         int[][] nums = { { 2 }, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 } };
         int n = nums.length;
         int m = nums[n - 1].length;
         int[][] dp = new int[n][m];
        System.out.println(tri_path_rec(nums, dp, 0, 0));
        System.out.println(tri_path_dp(nums));

    }

    // ===================================================================================================================================
    public static int[][] ispalindromesubstring_dp( String s) {
         int n = s.length();
         int[][] dp = new int[n][n];
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j) {
                    dp[i][j] = 1;
                    continue;
                }

                if (j - i == 1 && s.charAt(i) == s.charAt(j)) {
                    dp[i][j] = 2;
                    continue;
                }

                if (s.charAt(i) == s.charAt(j) && dp[i + 1][j - 1] != 0)
                    dp[i][j] = dp[i + 1][j - 1] + 2;

            }
        }
        return dp;
    }

    public static int countofpalindromesubstring_dp( String s) {
         int n = s.length();
        if (n == 1 || n == 0)
            return n;
         boolean[][] dp = new boolean[n][n];
        int count = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j)
                    dp[i][j] = true;
                else if (j - i == 1 && s.charAt(i) == s.charAt(j))
                    dp[i][j] = true;
                else
                    dp[i][j] = ((s.charAt(i) == s.charAt(j)) && dp[i + 1][j - 1]);

                if (dp[i][j])
                    count++;
            }
        }

        return count;
    }

    static int ans = 0;

    public static int countofpalindromesubstring_rec( String s,  int i,  int j,  int[][] dp) {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i == j)
            dp[i][j] = 1;
        else if (s.charAt(i) == s.charAt(j) && j - i == 1)
            dp[i][j] = 2; // we can not return from here bcoz then it will not check for i+1,j & i,j-1
        else if (s.charAt(i) == s.charAt(j) && countofpalindromesubstring_rec(s, i + 1, j - 1, dp) > 0)
            dp[i][j] = dp[i + 1][j - 1] + 2;
        else
            dp[i][j] = 0;

        countofpalindromesubstring_rec(s, i + 1, j, dp); // these are used to calculate all palindrome substring in
                                                         // every range
        countofpalindromesubstring_rec(s, i, j - 1, dp);

        if (dp[i][j] != 0)
            ans++;
        return dp[i][j];

    }

    public static String longestpalindromesubstring_dp( String s) {
         int n = s.length();
         int[][] dp = new int[n][n];
         int[] idx = new int[2];
        int len = Integer.MIN_VALUE;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j)
                    dp[i][j] = 1;
                else if (s.charAt(i) == s.charAt(j) && j - i == 1)
                    dp[i][j] = 2;
                else
                    dp[i][j] = (s.charAt(i) == s.charAt(j) && dp[i + 1][j - 1] != 0) ? dp[i + 1][j - 1] + 2 : 0;

                if (len < dp[i][j]) {
                    len = dp[i][j];
                    idx[0] = i;
                    idx[1] = j;
                }

            }
        }
        System.out.println(idx[0] + " " + idx[1]);
        return s.substring(idx[0], idx[1] + 1);
    }

    static int len = Integer.MIN_VALUE;

    public static int longestpalindromesubstring_rec( String s,  int[] idx,  int i,  int j,
             int[][] dp) // it will give tle
    {
        if (i > j)
            return 0;
        if (dp[i][j] > 0)
            return dp[i][j];
        if (i == j)
            dp[i][j] = 1;
        else if (s.charAt(i) == s.charAt(j) && j - i == 1)
            dp[i][j] = 2;
        else if (s.charAt(i) == s.charAt(j) && longestpalindromesubstring_rec(s, idx, i + 1, j - 1, dp) > 0)
            dp[i][j] = dp[i + 1][j - 1] + 2;
        else
            dp[i][j] = 0;
        longestpalindromesubstring_rec(s, idx, i, j - 1, dp);
        longestpalindromesubstring_rec(s, idx, i + 1, j, dp);
        if (len < dp[i][j]) {
            len = dp[i][j];
            idx[0] = i;
            idx[1] = j;
        }

        return dp[i][j];

    }

    public static String longestpalindromesubsequence_dp( String s) {
         int n = s.length();
         int[][] dp = new int[n][n];
        int st = 0;
        int e = 0;
        int len = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j)
                    dp[i][j] = 1;
                else if (s.charAt(i) == s.charAt(j) && j - i == 1)
                    dp[i][j] = 2;
                else if (s.charAt(i) == s.charAt(j) && dp[i + 1][j - 1] != 0)
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = Math.max(dp[i][j - 1], dp[i + 1][j]);

                if (len < dp[i][j]) {
                    len = dp[i][j];
                    st = i;
                    e = j;
                }
            }
        }
        System.out.println();
        display_2D(dp);
        return s.substring(st, e + 1);
    }

    static int len1 = 0;

    public static int longestpalindromesubsequence_rec( String s,  int start,  int end,  int[][] dp,
             int[] idx) {

        if (start > end)
            return 0;
        if (dp[start][end] != 0)
            return dp[start][end];
        if (start == end)
            return dp[start][end] = 1;

         int mid = longestpalindromesubsequence_rec(s, start + 1, end - 1, dp, idx);

         int left = longestpalindromesubsequence_rec(s, start, end - 1, dp, idx);
         int right = longestpalindromesubsequence_rec(s, start + 1, end, dp, idx);

        dp[start][end] = (s.charAt(start) == s.charAt(end)) ? mid + 2 : Math.max(left, right);
        if (len1 < dp[start][end]) {
            len1 = dp[start][end];
            idx[0] = start;
            idx[1] = end;
        }

        return dp[start][end];

    }

    public static int longestPalindromeSubsequence( String s,  int start,  int end,  int[][] dp) {
        if (start > end)
            return 0;
        if (dp[start][end] != 0)
            return dp[start][end];
        if (start == end)
            return dp[start][end] = 1;
         int mid = longestPalindromeSubsequence(s, start + 1, end - 1, dp);
         int left = longestPalindromeSubsequence(s, start, end - 1, dp);
         int right = longestPalindromeSubsequence(s, start + 1, end, dp);
        return dp[start][end] = (s.charAt(start) == s.charAt(end)) ? mid + 2 : Math.max(left, right);
    }

    public static int countofpalindromesubsequence_dp( String s) {
         int n = s.length();
         int[][] dp = new int[n][n];
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j)
                    dp[i][j] = 1;
                else if (s.charAt(i) == s.charAt(j))
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1;
                else
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            }
        }
        return dp[0][n - 1];
    }

    public static int countofpalindromesubsequence_rec( String s,  int start,  int end,
             int[][] dp) {
        if (start > end)
            return 0;
        if (dp[start][end] != 0)
            return dp[start][end];
        if (start == end)
            return dp[start][end] = 1;
         int mid = countofpalindromesubsequence_rec(s, start + 1, end - 1, dp);
         int left = countofpalindromesubsequence_rec(s, start, end - 1, dp);
         int right = countofpalindromesubsequence_rec(s, start + 1, end, dp);
        return dp[start][end] = (s.charAt(start) == s.charAt(end)) ? left + right + 1 : left + right - mid;
    }

    public static int count_Unique_PalindromicSubsequences( String s) {
        long mod1=(int)1e9+7;
         int n = s.length();
         long[][] dp = new long[n][n];
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j) {
                    dp[i][j] = 1;
                    continue;
                } else if (s.charAt(i) == s.charAt(j)) {
                    int left = i + 1;
                    int right = j - 1;
                    while (left <= right && s.charAt(i) != s.charAt(left))
                        left++;
                    while (left <= right && s.charAt(i) != s.charAt(right))
                        right--;
                     long add = (left < right) ? -dp[left + 1][right - 1] : (left == right) ? 1 : 2;
                    dp[i][j] = (2 * dp[i + 1][j - 1] + add)%mod1;
                } else
                    dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1])%mod1;

                if (dp[i][j] < 0)
                    dp[i][j] += mod;
            }
        }
        return (int) dp[0][n - 1];
    }

    public static int longestcommonsubstring_dp( String s1,  String s2) {
        int len = 0;
         int n1 = s1.length();
         int n2 = s2.length();
         int[][] dp = new int[n1][n2];
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                if (i == n1 - 1 || j == n2 - 1) {
                    dp[i][j] = (s1.charAt(i) == s2.charAt(j)) ? 1 : 0;
                    continue;
                }
                if (s1.charAt(i) == s2.charAt(j))
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                len = Math.max(len, dp[i][j]);
            }
        }
        return len;
    }

    public static int longestCommonSubsequence( String s1,  String s2) {
         int len = 0;
         int n1 = s1.length();
         int n2 = s2.length();
        if (n1 == 0 || n2 == 0)
            return 0;
         int[][] dp = new int[n1 + 1][n2 + 1];
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {

                if (s1.charAt(i) == s2.charAt(j))
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                else
                    dp[i][j] = Math.max(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        return dp[0][0];
    }

    public static int longestCommonSubsequence_rec( String s1,  String s2,  int i,  int j,
             int n1,  int n2,  int[][] dp) {
        if (i >= n1 || j >= n2)
            return 0;
        if (i == n1 - 1 && j == n2 - 1)
            return dp[i][j] = (s1.charAt(i) == s2.charAt(j)) ? 1 : 0;
        if (dp[i][j] != 0)
            return dp[i][j];
        int ans = 0;
        if (s1.charAt(i) == s2.charAt(j)) {
            ans = longestCommonSubsequence_rec(s1, s2, i + 1, j + 1, n1, n2, dp) + 1;
        } else {
            ans = Math.max(longestCommonSubsequence_rec(s1, s2, i + 1, j, n1, n2, dp),
                    longestCommonSubsequence_rec(s1, s2, i, j + 1, n1, n2, dp));
        }
        return dp[i][j] = ans;
    }

    // leetcode 583
    public static int minDelete( String s1,  String s2) {
         int n1 = s1.length();
         int n2 = s2.length();
         int[][] dp = new int[n1 + 1][n2 + 1];
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {

                if (s1.charAt(i) == s2.charAt(j))
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                else
                    dp[i][j] = Math.max(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        return (n1 + n2 - 2 * dp[0][0]);
    }

    // leetcode 718
    // leetcode 1092 , 730, 72, 121, 209
    public static int editDistance( String s1,  String s2) {
         int n = s1.length();
         int m = s2.length();
         int[][] dp = new int[n + 1][m + 1];
        for (int i = n; i >= 0; i--) {
            for (int j = m; j >= 0; j--) {
                if (i == n) {
                    dp[i][j] = m - j;
                    continue;
                }
                if (j == m) {
                    dp[i][j] = n - i;
                    continue;
                }

                if (s1.charAt(i) == s2.charAt(j))
                    dp[i][j] = dp[i + 1][j + 1];
                else
                    dp[i][j] = Math.min(dp[i + 1][j + 1], Math.min(dp[i + 1][j], dp[i][j + 1])) + 1;
            }
        }
        display_2D(dp);
        return dp[0][0];
    }

    public static int string_occurs_rec( String s1,  String s2,  int i,  int j,  int[][] dp) {
        if (j == s2.length())
            return dp[i][j] = 1;
        if ((s1.length() - i) < (s2.length() - j))
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s1.charAt(i) == s2.charAt(j))
            return dp[i][j] = string_occurs_rec(s1, s2, i + 1, j + 1, dp) + string_occurs_rec(s1, s2, i + 1, j, dp);
        return dp[i][j] = string_occurs_rec(s1, s2, i + 1, j, dp);
    }

    public static int string_occurs_dp( String s1,  String s2) {
         int n = s1.length();
         int m = s2.length();
         int[][] dp = new int[n + 1][m + 1];
        for (int i = n; i >= 0; i--) {
            for (int j = m; j >= 0; j--) {
                if (j == m) {
                    dp[i][j] = 1;
                    continue;
                }

                if (i == n || (s1.length() - i) < (s2.length() - j)) {
                    continue;
                }
                if (s1.charAt(i) == s2.charAt(j))
                    dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                else
                    dp[i][j] = dp[i + 1][j];

            }
        }
        display_2D(dp);
        return dp[0][0];
    }

    public static void strings() {
         String s = "dcabaab";
         int n = s.length();
         int[][] dp = ispalindromesubstring_dp(s);
        display_2D(dp);

        System.out.println("longest palindrome substring ");
         int[] idx = new int[2];
         int start = 0, end = n - 1;
         int[][] dp2 = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp2[i][j] = -1;
        System.out.println(longestpalindromesubstring_dp(s));
        longestpalindromesubstring_rec(s, idx, start, end, dp2);
        System.out.println(s.substring(idx[0], idx[1] + 1));
        display_2D(dp2);

        System.out.println("count of palindrome substring :");
        System.out.println(countofpalindromesubstring_dp(s));
         int[][] dp1 = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp1[i][j] = -1;
        System.out.println(countofpalindromesubstring_rec(s, 0, n - 1, dp1));
        display_2D(dp1);

        System.out.println(countofpalindromesubsequence_dp(s));
         int[][] dp3 = new int[n][n];
        System.out.println(countofpalindromesubsequence_rec(s, 0, n - 1, dp3));
        System.out.println("longest palindrome subsequence_dp: " + longestpalindromesubsequence_dp(s));
         int[][] dp4 = new int[n][n];
         int[] idx1 = new int[2];
        longestpalindromesubsequence_rec(s, 0, n - 1, dp4, idx1);
        display_2D(dp4);
        System.out.println("longest palindrome subsequence_rec: " + s.substring(idx[0], idx[1] + 1));
         int[][] dp5 = new int[n][n];
        System.out.println(longestPalindromeSubsequence(s, 0, n - 1, dp5));

         String s1 = "geeksforgeeks";
         String s2 = "geeksquiz";
         int n1 = s1.length();
         int n2 = s2.length();
        System.out.println(longestcommonsubstring_dp(s1, s2));
        System.out.println(longestCommonSubsequence(s1, s2));
         int[][] dp6 = new int[n1 + 1][n2 + 1];
        System.out.println(longestCommonSubsequence_rec(s1, s2, 0, 0, n1, n2, dp6));

        // minimum deletition 583
        System.out.println(minDelete(s1, s2));

        // leetcode 72
        System.out.println(editDistance("horse", "ros"));

        // no of times a string s2 occurs in s1
         int[][] dp7 = new int[6][4];
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 4; j++)
                dp7[i][j] = -1;
        }
        System.out.println(string_occurs_rec("aabbc", "abc", 0, 0, dp7));
        display_2D(dp7);
        System.out.println(string_occurs_dp("aabbc", "abc"));

        // count unique palindrome subsequence
        System.out.println(count_Unique_PalindromicSubsequences("abcdbacdacbdba"));

    }

    // ======================================================================================================================================

    // cutting rod
    static int max_cost = 0;

    public static void cutting_rod_void_type( int[] price,  int n,  int start,  int cost) {
        if (n == 0) {
            max_cost = Math.max(max_cost, cost);
            return;
        }

        for (int i = start; i < price.length; i++) {
            if (n - i - 1 >= 0)
                cutting_rod_void_type(price, n - i - 1, i, cost + price[i]);
        }
        return;
    }

    public static int cutting_rod_memo( int[] price,  int n,  int[] dp,  int start) {
        if (n == 0)
            return 0;

        int ans = 0;

        for (int i = start; i < price.length; i++) {
            if (n - i - 1 >= 0) {
                ans = Math.max(ans, cutting_rod_memo(price, n - i - 1, dp, i) + price[i]);
            }
        }
        return ans;

    }

    // leetcode 343
    public static int find( int n,  int start,  int dp[]) {
        if (n == 0 || n == 1)
            return dp[n] = 1;
        if (dp[n] != 0)
            return dp[n];
        int ans = 0;
        int max_ans = 0;
        for (int i = start; i <= n; i++) {
            if (n - i >= 0) {
                ans = i * find(n - i, i, dp);
                max_ans = Math.max(max_ans, ans);
            } else
                return max_ans;
        }
        return dp[n] = max_ans;
    }

    public static int integerBreak( int n) {
        if (n == 2 || n == 3)
            return n - 1;
         int[] dp = new int[n + 1];
        return find(n, 1, dp);
    }

    public static int decode_1_rec( String s,  int idx,  int[] dp) {
        if (idx == s.length())
            return dp[idx] = 1;
         char ch = s.charAt(idx);
        int count = 0;
        if (ch != '0')
            count += decode_1_rec(s, idx + 1, dp);
        if (idx + 1 < s.length()) {
             char ch1 = s.charAt(idx + 1);
             int n = (ch - '0') * 10 + (ch1 - '0');
            if (n >= 10 && n <= 26)
                count += decode_1_rec(s, idx + 2, dp);
        }
        return dp[idx] = count;

    }

    public static int decode_1_dp( String s) {
         int n = s.length();
         int[] dp = new int[n + 1];
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            int count = 0;
             char ch = s.charAt(i);
            if (ch != '0')
                count += dp[i + 1];
            if (i + 1 < n) {
                 char ch1 = s.charAt(i + 1);
                 int n0 = (ch - '0') * 10 + (ch1 - '0');
                if (n0 >= 10 && n0 <= 26)
                    count += dp[i + 2];
            }
            dp[i] = count;
        }
        return dp[0];

    }

    // leetcode 639
    static int m = (int) 1e9 + 7;

    public static long decode_2_rec( String s,  int idx,  long[] dp) {
        if (idx == s.length())
            return dp[idx] = 1;
        if (dp[idx] != 0)
            return dp[idx];
         char ch = s.charAt(idx);
        long count = 0;
        if (ch == '*') {
            count = (count + 9 * decode_2_rec(s, idx + 1, dp)) % m;
            if (idx + 1 < s.length()) {
                 char ch1 = s.charAt(idx + 1);
                if (ch1 == '*')
                    count = (count + 15 * decode_2_rec(s, idx + 2, dp)) % m;
                if (ch1 >= '0' && ch1 <= '6')
                    count = (count + 2 * decode_2_rec(s, idx + 2, dp)) % m;
                if (ch1 >= '7' && ch1 <= '9')
                    count = (count + decode_2_rec(s, idx + 2, dp)) % m;
            }
        } else if (ch != '0') {
            count = (count + decode_2_rec(s, idx + 1, dp)) % m;
            if (idx + 1 < s.length()) {
                 char ch2 = s.charAt(idx + 1);
                if (ch2 == '*') {
                    if (ch == '1')
                        count = (count + 9 * decode_2_rec(s, idx + 2, dp)) % m;
                    else if (ch == '2')
                        count = (count + 6 * decode_2_rec(s, idx + 2, dp)) % m;
                } else {
                     int no = (ch - '0') * 10 + (ch2 - '0');
                    if (no > 9 && no < 27)
                        count = (count + decode_2_rec(s, idx + 2, dp)) % m;
                }
            }
        }
        return dp[idx] = count % m;
    }

    public static int decode_2_dp( String s) {
         int n = s.length();
         int m1 = n + 1;
         long[] dp = new long[m1];
        dp[m1 - 1] = 1;
        for (int i = m1 - 2; i >= 0; i--) {
             char ch = s.charAt(i);
            long count = 0;
            if (ch == '*') {
                count = (count + 9 * dp[i + 1]) % m;
                if (i + 1 < n) {
                     char ch2 = s.charAt(i + 1);
                    if (ch2 == '*')
                        count = (count + 15 * dp[i + 2]) % m;
                    if (ch2 >= '0' && ch2 <= '6')
                        count = (count + 2 * dp[i + 2]) % m;
                    if (ch2 >= '7' && ch2 <= '9')
                        count = (count + dp[i + 2]) % m;
                }
            } else if (ch != '0') {
                count = (count + dp[i + 1]) % m;
                if (i + 1 < n) {
                     char ch2 = s.charAt(i + 1);
                    if (ch2 == '*') {
                        if (ch == '1')
                            count = (count + 9 * dp[i + 2]) % m;
                        if (ch == '2')
                            count = (count + 6 * dp[i + 2]) % m;
                    } else {
                         int value = (ch - '0') * 10 + (ch2 - '0');
                        if (value < 27)
                            count = (count + dp[i + 2]) % m;
                    }
                }
            }
            dp[i] = count;
        }
        return (int) dp[0];

    }

    static int mod1 = (int) 1e9 + 7;

    public static int distinctSubseqII( String s) {
         int n = s.length();
        if (n == 0 || n == 1)
            return n;
         long[] dp = new long[n + 1];
        dp[0] = 1;
         int[] vis = new int[27];
        for (int i = 1; i <= n; i++) {
             int ch = s.charAt(i - 1) - 'a';
            if (vis[ch] == 0) {
                dp[i] = (2 * dp[i - 1]) % mod1;
                vis[ch] = i;
            } else if (vis[ch] != 0) {
                dp[i] = (2 * dp[i - 1]) % mod1;
                 int idx = vis[ch];
                dp[i] = (dp[i] - dp[idx - 1]) % mod1;
                vis[ch] = i;
            }
        }
        long ans = dp[n] - 1;
        if (ans < 0)
            ans += mod1;
        return (int) ans;
    }

    // public static int palindrome_set( String s, Set<String> set, int i, int j)
    // {

    //     while(i>=0 && j<s.length());
    // }

    public static void practice()
    {  
        // rod cutting geeks
         int []price={3,5,8,9,10,20,17,20};
         int n=price.length;
         int [] dp=new int[n];
        cutting_rod_void_type(price,n,0,0);
        System.out.println(max_cost);
        System.out.println(cutting_rod_memo(price,n,dp,0));

        //leetcode 343 
        System.out.println(integerBreak(58));

        //leetcode 91
         String s="11203678";
         int[]dp1=new int[s.length()+1];
        System.out.println(decode_1_rec(s,0,dp1));
        System.out.println(decode_1_dp(s));

        //leetcode 639
         long[] dp2=new long[s.length()+1];
        System.out.println(decode_2_rec(s,0,dp2));
        System.out.println(decode_2_dp(s));


        //leetcode 940
        System.out.println(distinctSubseqII("abcdfesabcd"));


        //generate palindrome using set
        //  Set<String> hash=new Set<String>();
        //  String s2="bccb";
        // System.out.println(palindrome_set(s2,hash,0,s2.length()-1));


    }

    // ======================================================================================================================================
    public static int coin_change_perm_rec( int[] coins,  int target) {
        if (target == 0)
            return 1;

        int ans = 0;
        for (int i = 0; i < coins.length; i++) {
            if (coins[i] == 0)
                continue;
            if (target - coins[i] >= 0)
                ans += coin_change_perm_rec(coins, target - coins[i]);
        }
        return ans;
    }

    public static int coin_change_comb_rec( int[] coins,  int target,  int start) {
        if (target == 0)
            return 1;
        if (start == coins.length)
            return 0;
        int ans = 0;
        // for(int i=start;i<coins.length;i++)
        // {
        // if(target-coins[i]>=0)
        // ans+=coin_change_comb_rec(coins,target-coins[i],i);
        // }
        // you can write in 2 ways
        if (coins[start] == 0)
            return coin_change_comb_rec(coins, target, start + 1);
        if (target - coins[start] >= 0)
            ans += coin_change_comb_rec(coins, target - coins[start], start);
        ans += coin_change_comb_rec(coins, target, start + 1);
        return ans;
    }

    public static int coin_change_dp_perm( int[] coins,  int target) {

         int n = coins.length;
         int[] dp = new int[target + 1];
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for ( int coin : coins) {
                if (coin == 0)
                    continue;
                if (i - coin >= 0) {
                    dp[i] += dp[i - coin];
                }
            }
        }

        return dp[target];

    }

    // using this approach we can find solutions of n variable equation
    public static int coin_change_dp_comb( int[] coins,  int target) {

         int n = coins.length;
         int[] dp = new int[target + 1];
        dp[0] = 1;

        for ( int coin : coins) {
            if (coin == 0)
                continue;
            for (int t = 1; t <= target; t++) {

                if (t - coin >= 0)
                    dp[t] += dp[t - coin];
            }
        }
        return dp[target];

    }

    public static int target_sum_rec( int[] coins,  int idx,  int target,  int[][] dp) {
        if (target == 0)
            return dp[idx][target] = 1;
        if (idx == coins.length)
            return dp[idx][target] = 0;
        if (dp[idx][target] != -1)
            return dp[idx][target];
        int ans = 0;
        if (target - coins[idx] >= 0)
            ans += target_sum_rec(coins, idx + 1, target - coins[idx], dp);
        ans += target_sum_rec(coins, idx + 1, target, dp);
        return dp[idx][target] = ans;
    }

    // the dp array formed is just same as memo
    public static int target_sum_dp( int[] coins,  int target) {
         int[][] dp = new int[coins.length + 1][target + 1];
        dp[coins.length][0] = 1;
        for (int j = 0; j < dp[0].length; j++) {
            for (int i = dp.length - 2; i >= 0; i--) {
                if (j == 0) // this is necessary because my coins can have value 0
                {
                    dp[i][j] = 1;
                    continue;
                }
                // if(i==dp.length-1)
                // {
                // dp[i][j]=0;
                // continue;
                // }
                int ans = 0;
                if (j - coins[i] >= 0)
                    ans += dp[i + 1][j - coins[i]];
                ans += dp[i + 1][j];

                dp[i][j] = ans;
            }
        }

        display_2D(dp);
        return dp[0][dp[0].length - 1];
    }

    public static int target_sum_dp_02( int[] coins,  int target) {
         int n = coins.length;
         int m = target;
         int[][] dp = new int[n + 1][m + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (j == 0) {
                    dp[i][j] = 1;
                    continue;
                }
                int ans = 0;
                if (j - coins[i - 1] >= 0 && coins[i - 1] != 0)
                    ans += dp[i - 1][j - coins[i - 1]];
                ans += dp[i - 1][j];
                dp[i][j] = ans;
            }
        }
        System.out.println();
        display_2D(dp);
        return dp[n][m];
    }

    public static void coin_change() {
         int coins[] = { 2, 3, 5, 0 };
         int target = 10;
        System.out.println(coin_change_perm_rec(coins, 10)); // infinite times
        System.out.println(coin_change_comb_rec(coins, 10, 0));

        System.out.println(coin_change_dp_perm(coins, target));
        System.out.println(coin_change_dp_comb(coins, target));

        // standard question find target using every coin only once irrespective of any
        // sequence
         int[][] dp = new int[coins.length + 1][target + 1];
        for (int i = 0; i < dp.length; i++) {
            for (int j = 0; j < dp[0].length; j++)
                dp[i][j] = -1;
        }
        System.out.println(target_sum_rec(coins, 0, target, dp)); // no multiple occurences
        display_2D(dp);
        System.out.println(target_sum_dp(coins, target));
        System.out.println(target_sum_dp_02(coins, target));

    }

    // =====================================================================================================================================
    public static int LIS_DP( int[] arr,  int[] dp) {
         int n = arr.length;
        dp[0] = 1;
        int ans = 1;
        for (int i = 1; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j]) {
                    dp[i] = Math.max(dp[j] + 1, dp[i]);
                }
            }
            ans = Math.max(ans, dp[i]);
        }
        return ans;
    }

    public static int LDS_DP_reverse( int[] arr,  int[] dp) {
         int n = arr.length;
        dp[n - 1] = 1;
        int ans = 1;
        for (int i = n - 2; i >= 0; i--) {
            dp[i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    dp[i] = Math.max(dp[j] + 1, dp[i]);
                }
            }
            ans = Math.max(dp[i], ans);
        }
        System.out.println();
        return ans;

    }

    public static int LDS_DP_forward( int[] arr) {
         int n = arr.length;
         int[] dp = new int[n];
        dp[0] = 1;
        int ans = 1;
        for (int i = 1; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (arr[i] < arr[j]) {
                    dp[i] = Math.max(dp[j] + 1, dp[i]);
                }
            }
            ans = Math.max(ans, dp[i]);
        }
        System.out.println();
        return ans;
    }

    public static int LBS( int[] arr1) {
         int[] Lis = new int[arr1.length];
         int[] Lds = new int[arr1.length];
        LIS_DP(arr1, Lis);
        LDS_DP_reverse(arr1, Lds);
        int ans = 0;
        for (int i = 0; i < arr1.length; i++) {
            ans = Math.max(Lis[i] + Lds[i] - 1, ans);
        }
        return ans;
    }

    public static int max_sum_increasing_subseq( int[] arr) {

         int n = arr.length;
         int[] dp = new int[n];
        dp[0] = arr[0];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            dp[i] = arr[i];
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j])
                    dp[i] = Math.max(dp[i], dp[j] + arr[i]);
            }
            ans = Math.max(ans, dp[i]);
        }
        return ans;
    }

    public static int min_deletion_to_sort( int[] arr) {

         int n = arr.length;
         int[] dp = new int[n];
        dp[0] = 1;
        int ans = 0;
        for (int i = 1; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (arr[i] >= arr[j])
                    dp[i] = Math.max(dp[i], dp[j] + 1);
            }
            ans = Math.max(ans, dp[i]);
        }
        return n - ans;
    }

    public static int count_LIS( int[] arr) {
         int n = arr.length;
         int[] dp = new int[n];
         int[] count = new int[n];
        dp[0] = count[0] = 1;
        int ans = 0;
        int maxlen = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            count[i] = 1;
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j]) {
                    if (dp[i] == dp[j] + 1) {
                        count[i] += count[j];
                    }
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                }
            }
            if (ans == dp[i])
                maxlen += count[i];
            if (ans > dp[i]) {
                maxlen = count[i];
                ans = dp[i];
            }

        }
        return maxlen;
    }

    public static void bitonic() {
         int[] arr = { 10, 22, 9, 33, 21, 50, 41, 60, 90 };
         int[] arr1 = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 15 };
        System.out.println(LIS_DP(arr1, new int[arr1.length]));

        System.out.println(LDS_DP_reverse(arr1, new int[arr1.length]));
        System.out.println(LDS_DP_forward(arr1));
        System.out.println(LBS(arr1));

        System.out.println(max_sum_increasing_subseq(arr));

        System.out.println(min_deletion_to_sort(arr1));

        // leetcode 673
        System.out.println(count_LIS(arr1));

        // leetcode 354

    }
    // =====================================================================================================================================

    public static int mcm_rec( int[] arr,  int[][] dp,  int start,  int end) {
        if (start >= end)
            return 0;
        if (start == end - 1)
            return dp[start][end] = 0;
        if (start + 1 == end - 1)
            return dp[start][end] = arr[start] * arr[start + 1] * arr[end];
        if (dp[start][end] != -1)
            return dp[start][end];
        int max_ans = (int) 1e9;
        for (int cut = start + 1; cut < end; cut++) {
             int ans = mcm_rec(arr, dp, start, cut) + arr[start] * arr[cut] * arr[end]
                    + mcm_rec(arr, dp, cut, end);
            max_ans = Math.min(ans, max_ans);
        }
        return dp[start][end] = max_ans;
    }

    public static int mcm_dp( int[] arr) {

         int n = arr.length;
         int[][] dp = new int[n][n];
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j)
                    continue;
                if (i == j - 1) {
                    dp[i][j] = 0;
                    continue;
                }
                int min_ans = (int) 1e9;
                for (int cut = i + 1; cut < j; cut++) {
                     int ans = dp[i][cut] + arr[i] * arr[cut] * arr[j] + dp[cut][j];
                    min_ans = Math.min(ans, min_ans);
                }
                dp[i][j] = min_ans;
            }
        }
        display_2D(dp);
        return dp[0][n - 1];
    }

    // https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication/0/
    public static String mcm_string_dp( int[] arr) {
         int n = arr.length;
         int[][] dp = new int[n][n];
         String[][] sdp = new String[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                sdp[i][j] = "";
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (i == j - 1) {
                    dp[i][j] = 0;
                    sdp[i][j] = (char) (i + 'A') + "";
                    continue;
                }
                int min_ans = (int) 1e9;
                String ans1 = "";
                for (int cut = i + 1; cut < j; cut++) {
                     int ans = dp[i][cut] + arr[i] * arr[cut] * arr[j] + dp[cut][j];
                    if (ans < min_ans) {
                        min_ans = ans;
                        ans1 = '(' + sdp[i][cut] + sdp[cut][j] + ')';
                    }
                }
                dp[i][j] = min_ans;
                sdp[i][j] = ans1;

            }
        }
        return sdp[0][n - 1];
    }

    // leetcode 132
    public static boolean[][] find_palindrome( String s) {
         int n = s.length();
         boolean[][] dp = new boolean[n][n];
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j)
                    dp[i][j] = true;
                else if (s.charAt(i) == s.charAt(j) && j - i == 1)
                    dp[i][j] = true;
                else
                    dp[i][j] = (s.charAt(i) == s.charAt(j) && dp[i + 1][j - 1] == true);
            }
        }
        return dp;
    }

    public static int palindrome_partitioning_rec( String s,  boolean[][] dp,  int start,  int end,
             int[] dp1) {
        if (start >= end)
            return 0;
        if (dp[start][end])
            return 0;
        if (dp1[start] != -1)
            return dp1[start];

        int min_ans = (int) 1e9;
        for (int cut = start; cut <= end; cut++) {
            if (dp[start][cut]) {
                 int ans = palindrome_partitioning_rec(s, dp, cut + 1, end, dp1) + 1;
                min_ans = Math.min(min_ans, ans);
            }
        }
        return dp1[start] = min_ans;
    }

    public static int palindrome_partitioning_dp( String s,  boolean[][] dp) {
         int end = s.length() - 1;
         int[] dp1 = new int[end + 1];
        dp1[end] = 0;
        for (int start = end - 1; start >= 0; start--) {
            int min_ans = (int) 1e9;
            for (int cut = start; cut < end; cut++) {
                if (dp[start][cut]) {
                     int ans = (dp[cut + 1][end] == true) ? 0 : dp1[cut + 1];
                    System.out.print(ans + " ");
                    min_ans = Math.min(min_ans, ans + 1);
                }

                dp1[start] = min_ans;
            }
        }

        return dp1[0];
    }

    public static int total_sum( int start,  int end,  int[] fre) {
        int sum = 0;
        for (int i = start; i <= end; i++)
            sum += fre[i];
        return sum;
    }

    public static int wildcard_matching( String s1,  String s2,  int i,  int j,  int[][] dp) {
        if (i == s1.length() && j == s2.length())
            return dp[i][j] = 1;
        if (i == s1.length() || j == s2.length()) {
            if (i != s1.length())
                return dp[i][j] = 0;
            if (j == s2.length() - 1 && s2.charAt(j) == '*')
                return dp[i][j] = 1;
            else
                dp[i][j] = 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        boolean ans = false;
        if (s1.charAt(i) == s2.charAt(j) || s2.charAt(j) == '?')
            ans = wildcard_matching(s1, s2, i + 1, j + 1, dp) == 1;
        else if (s2.charAt(j) == '*') {
            ans = ans || wildcard_matching(s1, s2, i + 1, j, dp) == 1;
            ans = ans || wildcard_matching(s1, s2, i, j + 1, dp) == 1;
        }
        return dp[i][j] = ans ? 1 : 0;
    }

    public static String remove_star( String s) {
         StringBuilder s1 = new StringBuilder();
        boolean ch = false;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != '*') {
                s1.append(s.charAt(i));
                ch = false;
            } else {
                if (ch == false)
                    s1.append(s.charAt(i));
                ch = true;
            }
        }
        return s1.toString();
    }

    public static int optimal_bst( int[] fre,  int start,  int end,  int[][] dp) {
        if (start > end)
            return 0;
        if (start == end)
            return dp[start][end] = fre[start];
        if (dp[start][end] != 0)
            return dp[start][end];
        int min_ans = (int) 1e8;
        for (int cut = start; cut <= end; cut++) {
             int left = optimal_bst(fre, start, cut - 1, dp);
             int right = optimal_bst(fre, cut + 1, end, dp);
            min_ans = Math.min(min_ans, left + right);
        }
        return dp[start][end] = (min_ans == (int) 1e8) ? 0 : min_ans + total_sum(start, end, fre);
    }

    public static int optimal_bst_dp( int[] fre) {
         int n = fre.length;
         int[][] dp = new int[n][n];
        for (int start = n - 1; start >= 0; start--) {
            for (int end = start; end < n; end++) {
                if (start == end) {
                    dp[start][end] = fre[start];
                    continue;
                }

                int ans = (int) 1e8;
                for (int cut = start; cut <= end; cut++) {
                     int left = (cut == start) ? 0 : dp[start][cut - 1];
                     int right = (cut == end) ? 0 : dp[cut + 1][end];
                    ans = Math.min(ans, left + right);
                }
                dp[start][end] = (ans == (int) 1e8) ? 0 : ans + total_sum(start, end, fre);
            }
        }
        display_2D(dp);
        return dp[0][n - 1];
    }

    public static int unique_BST( int n) {
        if (n == 0 || n == 1)
            return n;
         int[][] dp = new int[n + 1][n + 1];
        for (int start = n; start > 0; start--) {
            for (int end = start; end <= n; end++) {
                if (start == end) {
                    dp[start][end] = 1;
                    continue;
                }
                int ans = 0;
                for (int root = start; root <= end; root++) {
                     int left = (root == start) ? 1 : dp[start][root - 1];
                     int right = (root == end) ? 1 : dp[root + 1][end];
                    ans += left * right;
                }
                dp[start][end] = ans;
            }
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++)
                System.out.print(dp[i][j] + "  ");
            System.out.println();
        }
        return dp[1][n];
    }

    public static void mcm() {
         int[] arr = { 40, 20, 30, 10, 30 };
         int n = arr.length;
         int[][] dp = new int[arr.length][arr.length];
         int start = 0;
         int end = arr.length - 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                dp[i][j] = -1;
        }
        System.out.println(mcm_rec(arr, dp, start, end));
        display_2D(dp);

        System.out.println(mcm_dp(arr));

        // print string with min multiplication
        System.out.println(mcm_string_dp(arr));

        // leetcode 132
         String s = "abccbddcddff";
         boolean[][] is_palindrome = find_palindrome(s);
         int[] dp1 = new int[s.length()];
        for (int i = 0; i < s.length(); i++)
            dp1[i] = -1;
        System.out.println(palindrome_partitioning_rec(s, is_palindrome, 0, s.length() - 1, dp1));
        System.out.println(palindrome_partitioning_dp(s, is_palindrome));

        // optimal bst
         int[] key = { 10, 12, 20 };
         int[] fre = { 34, 8, 50 };
         int[][] dp2 = new int[key.length][key.length];
        System.out.println(optimal_bst(fre, 0, key.length - 1, dp2));
        display_2D(dp2);
        System.out.println(optimal_bst_dp(fre));

        // find unique bst
        System.out.println(unique_BST(10));

        // wildcard matching
         String s1 = "acdcb";
        String p = "a***c***b";
        p = remove_star(p);
         int[][] dp3 = new int[s1.length() + 1][p.length() + 1];
       for(int i=0;i<=s1.length();i++)
       {
        for(int j=0;j<=p.length();j++)
            dp3[i][j]=-1;
       }
       System.out.println(p);
       System.out.println(wildcard_matching(s1,p,0,0,dp3)==1);
    }

    public static void solve()
	{
		// fibonacci();
		// mazepath();
		// dice();
		// climb_stairs();
		// mincostpath();  
		// goldmine();
		// pair_and_single();
  //       divide_in_kgroups();
  //       jump_game();
  //       triangle_path();
  //          strings();
          practice();
   //        coin_change();
   //        bitonic();
            // mcm();


	}















}