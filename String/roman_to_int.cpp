int Solution::romanToInt(string A) {
        char previous = ' ';
        int sol = 0;
        
        for (auto x : A) {
            if (x == 'M')
                sol += (previous == 'C') ? 800 : 1000;
            else if (x == 'D')
                sol += (previous == 'C') ? 300 : 500;
            else if (x == 'C')
                sol += (previous == 'X') ? 80 : 100;
            else if (x == 'L')
                sol += (previous == 'X') ? 30 : 50;
            else if (x == 'X')
                sol += (previous == 'I') ? 8 : 10;
            else if (x == 'V')
                sol += (previous == 'I') ? 3 : 5;
            else if (x == 'I')
                sol++;
            
            previous = x;
        }
        
        return sol;

}    
