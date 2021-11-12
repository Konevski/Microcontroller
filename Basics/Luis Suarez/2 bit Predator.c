#include <stdio.h>
#include <stdlib.h>
#define StronglyNotTaken
#define weaklyNotTaken
#define weaklyTaken
#define StronglyTaken

int main()
{
    int event = 1;
    int state=StronglyTaken;

    switch (state)
    {
    case StronglyNotTaken:
        if (event == 1)
        {
            state = weaklyNotTaken;
        }

        break;
    case weaklyNotTaken:
        if (event == 0)
        {
            state = StronglyNotTaken;
        }
        else if (event == 1)
        {
            state = weaklyTaken;
        }
        break;

    case weaklyTaken:

        if (event == 0)
        {
            state = weaklyNotTaken;
        }
        else if (event == 1)
        {
            state = StronglyTaken;
        }
        break;

    case StronglyTaken:

        if (event == 0)
        {

            state = weaklyTaken
        }
        break;
    }
    return=0;
}
}
