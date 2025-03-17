function my_levenshtein(s1, s2)
{
    var inc = 0 ;
    if(s1.length==s2.length)
    {
        for( i=0 ; i < s1.length ; i++)
        {
            if(s1[i]!=s2[i])
            {
                inc++
            }
        }
        return inc ;
    }
    else
    {
        return -1 ;
    }
}