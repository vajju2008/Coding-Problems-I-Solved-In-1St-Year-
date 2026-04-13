import java.io.*;
import java.util.*;
class Codechef{
    public static void main(String[] args) throws Exception{
        FastScanner fs=new FastScanner(System.in);
        PrintWriter out=new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        int t=fs.nextInt();
        while(t-->0){
            int n=fs.nextInt();
            
            long[] a=new long[n];
            
            long[] b=new long[n];
            
            for(int i=0;i<n;i++) a[i]=fs.nextLong();
            
            
            for(int i=0;i<n;i++) b[i]=fs.nextLong();
            
            
            long[] la=new long[n];
            
            long[] ra=new long[n];
            
            long[] lb=new long[n];
            
            long[] rb=new long[n];
            
            long cur=a[0];
            
            la[0]=cur;
            
            for(int i=1;i<n;i++){
                
                cur = Math.max(a[i], cur + a[i]);
                
                la[i]=cur;
                
            }
            cur=a[n-1];
            ra[n-1]=cur;
            for(int i=n-2;i>=0;i--){
                cur = Math.max(a[i], cur + a[i]);
                ra[i]=cur;
            }
            cur=b[0];
            lb[0]=cur;
            for(int i=1;i<n;i++){
                cur = Math.max(b[i], cur + b[i]);
                lb[i]=cur;
            }
            cur=b[n-1];
            
            rb[n-1]=cur;
            
            for(int i=n-2;i>=0;i--){
                
                cur = Math.max(b[i], cur + b[i]);
                
                rb[i]=cur;
                
            }
            long ans=Long.MIN_VALUE;
            for(int i=0;i<n;i++){
                long bestA = la[i] + ra[i] - a[i];// bestA
                
                long bestB = lb[i] + rb[i] - b[i]; // bestb 
                
                ans = Math.max(ans, bestA + bestB);
                
            }
            out.println(ans);
        }
        out.flush();
    }
    static class FastScanner{ // FastScanner
        private final InputStream in; // InputStream
        
        private final byte[] buffer = new byte[1<<16]; // final bit
        
        private int ptr=0, len=0;
        
        FastScanner(InputStream is){ in=is; }
        
        private int read() throws IOException{
            if(ptr>=len){
                
                len=in.read(buffer);
                
                ptr=0;
                if(len<=0) return -1;
            }
            return buffer[ptr++];
        }
        int nextInt() throws IOException{
            int c;
            while((c=read())<=32){
                if(c<0) return -1;
            }
            int s=1;
            if(c=='-'){ s=-1; c=read(); }
            int val=0;
            while(c>32){
                val = val*10 + (c-'0');
                c = read();
            }
            return val*s;
        }
        long nextLong() throws IOException{
            int c;
            while((c=read())<=32){
                if(c<0) return -1;
            }
            int s=1;
            if(c=='-'){ s=-1; c=read(); }
            long val=0;
            
            while(c>32){
                val = val*10 + (c-'0');
                c = read();
            }
            return val*s; // 
            
        }
    }
}