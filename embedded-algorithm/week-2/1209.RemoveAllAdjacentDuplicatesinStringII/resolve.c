int count_number(char* s)
{
    int count = 0;
    while(s[count] != '\0')
    {
        count++;
    }
    return count;
}
char* removeDuplicates(char* s, int k) {
    int len = count_number(s);
    int count = 0;
    int repeat_stack[len];
    for(int i = 0; i < len; i++)
    {
        s[count] = s[i];
        if (count > 0 && s[count - 1] == s[count])
        {
            repeat_stack[count] = repeat_stack[count - 1] + 1;
        }
        else
        {
            repeat_stack[count] = 1;
        }
        count++;
        if(repeat_stack[count - 1] == k)
        {
            count -= k;
        }
    } 
    s[count] = '\0';
    return s;
}