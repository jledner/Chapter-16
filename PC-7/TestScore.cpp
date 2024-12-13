#include <iostream>
using namespace std;

class TestScores {
private:
    double* scores;
    int length;
public:
    TestScores(double s[], int l) {
        length = l;
        scores = new double[length];
        for (int i = 0; i < length; i++) {
            scores[i] = s[i];
            if (scores[i] < 0 || scores[i] > 100)
                throw OOBException(scores[i]);
        }
    }

    double average() {
        double sum;
        for (int i = 0; i < length; i++) {
            sum += scores[i];
        }
        return sum / length;
    }

    class OOBException {
    private:
        double OOBscore;
    public:
        OOBException(double s) : OOBscore(s) {}
        double getOOBScore() { return OOBscore; }
    };
};

int main() {
    double arr[] = { 99.9, 78.3, 88.3, 92.9, 109.4 };
    try {
        TestScores myScores = TestScores(arr, 5);
        cout << "Average: " << myScores.average() << endl;
    }
    catch (TestScores::OOBException e) {
        cout << "The entered score " << e.getOOBScore() << " is out of bounds." << endl;
    }

    return 0;
}