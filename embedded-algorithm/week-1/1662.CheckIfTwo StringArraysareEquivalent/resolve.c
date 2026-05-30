bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size) {
    int index_1 = 0, index_2 = 0;
    int i = 0, j = 0;
    while(i < word1Size && j < word2Size)
    {
        if(word1[i][index_1] != word2[j][index_2])
            return false;
        index_1++;
        index_2++;
        if(word1[i][index_1] == '\0')
        {
            i++;
            index_1 = 0;
        }
        if(word2[j][index_2] == '\0')
        {
            j++;
            index_2 = 0;
        }
    }
    return (i == word1Size && j == word2Size);
}