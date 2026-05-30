char* makeGood(char* s) {
    uint8_t stack_s = 0;
    for(uint8_t i = 0; s[i] != '\0'; i++)
    {
        if(stack_s > 0 && (s[stack_s - 1] - s[i] == 32 || s[i] - s[stack_s - 1] == 32))
        {
            stack_s--;
        }
        else
        {
            s[stack_s] = s[i];
            stack_s++;
        }
    }
    s[stack_s] = '\0';
    return s;
}