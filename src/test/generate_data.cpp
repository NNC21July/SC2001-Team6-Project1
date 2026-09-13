#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <num_integers> <output_filename>" << std::endl;
        return 1;
    }

    int n = std::stoi(argv[1]);
    std::string filename = argv[2];

    std::ofstream outputFile(filename);
    if (!outputFile) {
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return 1;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 10000000); // Random integers between 1 and 10 million

    for (int i = 0; i < n; ++i) {
        outputFile << distrib(gen) << std::endl;
    }

    outputFile.close();
    std::cout << "Successfully generated " << n << " random integers in " << filename << std::endl;
    return 0;
}
