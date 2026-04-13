import java.io.*;
import java.util.*;
class Codechef{
    static final long NEGINF = Long.MIN_VALUE/4; // lol hacky way to represent -inf
    static final long MOD = 998244353L; // the magic mods number, hope I dont forget

    public static void main(String[] args) throws Exception{
        FastScanner fs = new FastScanner(System.in); // fast input, cuz Scanner is too slow
        int T = fs.nextInt(); // number of test cases
        StringBuilder out = new StringBuilder(); // collect output, print once at end (less TLE)

        while(T-->0){ // loop over test cases, shortcut style
            int n = fs.nextInt(); // number of vertices
            long[] a = new long[n+1]; // values on vertices (1-i
            long minAbs = Long.MAX_VALUE; // track min abs value, used later for fallback

            // read vertex values
            for(int i=1;i<=n;i++){ 
                a[i]=fs.nextLong(); 
                minAbs = Math.min(minAbs, Math.abs(a[i])); // keep smallest abs
            }

            // adjacency list for tree
            ArrayList<Integer>[] g = new ArrayList[n+1];
            for(int i=1;i<=n;i++) g[i]=new ArrayList<>();
            for(int i=0;i<n-1;i++){ // read edges
                int u=fs.nextInt(), v=fs.nextInt();
                g[u].add(v); g[v].add(u); // undirected
            }

         
            int root = 1; // just pick 1 as root, lazy
            int[] parent = new int[n+1];
            int[] order = new int[n];
            int idx=0;
            int[] st = new int[n]; // manual stack, no recursion
            int sp=0;
            st[sp++]=root; parent[root]=0;
            while(sp>0){
                int u=st[--sp];
                order[idx++]=u;
                for(int v:g[u]) if(v!=parent[u]){
                    parent[v]=u;
                    st[sp++]=v;
                }
            }

            // dp arrays: dp0 = best sum with even parity, dp1 = odd parity
            long[] dp0 = new long[n+1];
            long[] dp1 = new long[n+1];
            Arrays.fill(dp0, NEGINF);
            Arrays.fill(dp1, NEGINF);

            // process nodes in reverse order 
            for(int i=n-1;i>=0;i--){
                int u = order[i];
                int p = a[u]<0 ? 1:0; // parity bit
                long base = Math.abs(a[u]); // weight
                long cur0 = NEGINF, cur1 = NEGINF;
                if(p==0) cur0 = base; else cur1 = base; // init state

                // merge children
                for(int v:g[u]) if(v!=parent[u]){
                    long c0 = dp0[v], c1 = dp1[v];
                    long n0 = cur0, n1 = cur1;
                    // combine states, messy but works
                    if(cur0>NEGINF && c0>NEGINF) n0 = Math.max(n0, cur0 + c0);
                    if(cur1>NEGINF && c1>NEGINF) n0 = Math.max(n0, cur1 + c1);
                    if(cur1>NEGINF && c0>NEGINF) n1 = Math.max(n1, cur1 + c0);
                    if(cur0>NEGINF && c1>NEGINF) n1 = Math.max(n1, cur0 + c1);
                    cur0 = n0; cur1 = n1;
                }
                dp0[u]=cur0; dp1[u]=cur1;
            }

            // find best even-parity sum
            long bestEven = NEGINF;
            for(int i=1;i<=n;i++) if(dp0[i]>bestEven) bestEven=dp0[i];

            long ans;
            if(bestEven>NEGINF){
                // yay we found even parity, computersssss 
                long exp = modExpReduce(bestEven, MOD-1); // reduce exponent mod
                ans = modPow(2, exp, MOD);
            } else {
                // fallback: no even parity, use minAbs trick 
                long exp = modExpReduce(minAbs, MOD-1);
                long v = modPow(2, exp, MOD);
                ans = (MOD - v)%MOD; // negative result modded
            }
            out.append(ans).append('\n'); // collect answer
        }
        System.out.print(out.toString()); // finally print all the values 
    }

    // modular exponentiation (binary exp)
    static long modPow(long b, long e, long m){
        long r=1% m; // start with 1
        long x=b% m; // reduce base
        while(e>0){
            if((e&1)==1) r = (r*x)%m; 
            x = (x*x)%m; // square
            e >>= 1; // shift
        }
        return r;
    }

    
    static long modExpReduce(long val, long modm){
        long res = val % modm;
        if(res<0) res += modm; // fix - ve 
        return res;
    }

    // fast as flashh 💣scanner 
    static class FastScanner{
        private final InputStream in;
        private final byte[] buffer = new byte[1<<16]; // big buffer
        private int ptr=0, len=0;
        FastScanner(InputStream is){ in=is; }
        private int read() throws IOException{
            if(ptr>=len){
                len = in.read(buffer);
                ptr = 0;
                if(len<=0) return -1; // eOf
            }
            return buffer[ptr++];
        }
        long nextLong() throws IOException{ return Long.parseLong(next()); }
        int nextInt() throws IOException{ return Integer.parseInt(next()); }
        String next() throws IOException{
            StringBuilder sb = new StringBuilder();
            int c;
            while((c=read())<=32){ // skip thee spacess
                if(c==-1) return ""; // EoF
            }
            do{ sb.append((char)c); c=read(); } while(c>32 && c!=-1);
            return sb.toString();
        }
    }
}
