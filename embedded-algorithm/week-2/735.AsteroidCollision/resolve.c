int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int *asteroids_stack = (int*)malloc(asteroidsSize * sizeof(int));
    int stack_s = 0;
    for(int i = 0; i < asteroidsSize; i++)
    {
        int collide = 0;
        while(stack_s > 0 && asteroids_stack[stack_s - 1] > 0 && asteroids[i] < 0)
        {
            if(asteroids_stack[stack_s - 1] < -asteroids[i])
            {
                stack_s--;
            }
            else if (asteroids_stack[stack_s - 1] == -asteroids[i])
            {
                stack_s--;
                collide = 1;
                break;
            }
            else
            {
                collide = 1;
                break;
            }
        }
        if (collide == 0)
        {
            asteroids_stack[stack_s] = asteroids[i];
            stack_s++; 
        } 
    }
    *returnSize = stack_s;
    return asteroids_stack;
}