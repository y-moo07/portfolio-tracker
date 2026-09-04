#include <iostream>
#include <string>
#include <vector>

class Position {

    private:
        double entryPrice;

    public:
        std::string ticker;
        int shares;

    Position(std::string init_ticker, int init_shares, double init_entryPrice) {
        ticker = init_ticker;
        shares = init_shares;
        entryPrice = init_entryPrice;
    }

    double currentValue(double currentPrice) {
        return shares*currentPrice;
    }

    double profitLoss(double currentPrice) {
        return shares*(currentPrice - entryPrice);
    }

};

int countProfitable(std::vector<Position> positions, std::vector<double> currentPrices) {
    int count = 0;

    for (int i = 0; i < positions.size(); i++) {
        if (positions[i].profitLoss(currentPrices[i]) > 0) {
            count++;
        }
    }
    return count;
}

int main() {

    double totalPortfolio = 0;
    double totalProfitLoss = 0;
    std::vector<Position> positions = { {"AAPL", 30, 175.50}, {"TSLA", 15, 260.0}, {"NVDA", 10, 410.25}, {"SPY", 25, 430.0}};
    std::vector<double> currentPrices = {188.75, 245.80, 495.60, 438.90};

    for (int i = 0; i < positions.size(); i++) {
        std::cout << positions[i].ticker << "\n" << "Current Value: " << positions[i].currentValue(currentPrices[i]) << "\n" << "Profit/Loss: " << positions[i].profitLoss(currentPrices[i]) << std::endl;
        std::cout << std::endl;

        totalPortfolio += positions[i].currentValue(currentPrices[i]);
        totalProfitLoss += positions[i].profitLoss(currentPrices[i]);

    }

    std::cout << "Total Portfolio Value: " << totalPortfolio << "\n";
    std::cout << "Total Profit/Loss: " << totalProfitLoss << std::endl;

    std::cout << std::endl;

    std::cout << "Number of positions profitable: " << countProfitable(positions, currentPrices) << std::endl;

    return 0;
}