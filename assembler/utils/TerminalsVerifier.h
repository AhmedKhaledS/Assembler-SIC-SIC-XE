#ifndef TERMINALSVERIFIER_H
#define TERMINALSVERIFIER_H


class TerminalsVerifier
{
    public:
        static void setStartExistance(bool exist);
        static void setEndExistance(bool exist);
        static bool getStartExistance();
        static bool getEndExistance();

    private:
        static bool startExistance;
        static bool endExistance;
};

#endif // TERMINALSVERIFIER_H
