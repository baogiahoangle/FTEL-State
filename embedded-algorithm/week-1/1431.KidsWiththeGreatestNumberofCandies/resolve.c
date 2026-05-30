bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    int max = candies[0];
    bool* result_candies = (bool*)malloc(candiesSize*sizeof(bool));
    for(int i = 1; i < candiesSize; i++)
    {
        if (max < candies[i])
            max = candies[i];
    }
    for(int i = 0; i < candiesSize; i++)
    {
        if(candies[i] + extraCandies >= max)
            result_candies[i] = true;
        else
            result_candies[i] = false;
    }
    *returnSize = candiesSize;
    return result_candies;
}