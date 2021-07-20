#include <server.h>
#include <algorithm>
#include <random>

using namespace ucm;

std::vector<std::string> readWordsFile(std::string filename){
	std::ifstream file(filename);
	std::string str; 

	std::vector<std::string> words;

	while (std::getline(file, str)){
		words.push_back(boost::to_upper_copy(str));
		
	}

	return words;
}


int main(int argc, char** argv){

    Server server(argc, argv);

    server.renderHTML("/", "index.html");

    server.route("/list", [&](const request& req, response& res){

        std::uniform_int_distribution<> distribution(65, 90);
        std::mt19937 gen;
        gen.seed(std::random_device()());

        json temp;

        for (int i = 0; i < 9; i++){
            temp.push_back(distribution(gen));
        }

        res.sendJSON(temp);
    });

    server.route("/checkWord", [&](const request& req, response& res){
        if (req.has_params({"word"})){
            std::string word = req.url_params.get("word");

            std::vector<std::string> allTheWords = readWordsFile("misc/english.txt");

            bool found = find(allTheWords.begin(), allTheWords.end(), word) != allTheWords.end();

            json temp;
            temp["word"] = word;
            temp["valid"] = found;

            res.sendJSON(temp);
        }
        else {
            res.sendError400();
        }
    });

    server.run();
}
