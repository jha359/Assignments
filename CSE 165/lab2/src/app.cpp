#include <server.h>
#include <search.h>

using namespace ucm;


int main(int argc, char** argv){

    // Do not delete this line. It initializes the data store.
    init();

    Server server(argc, argv);

    server.renderHTML("/", "index.html");

    server.route("/search", [&](const request& req, response& res){
        // Provide your code here. 
        ucm::json results;
        if(req.has_params({"q"}))
        {
            std::string q = req.url_params.get("q");

            results = search(q);
            res.sendJSON(results);
        }
        else
        {
            results["attempt"] = "none";
            results["result"] = getAll();
            res.sendJSON(results);
        }
    });

    server.run();
}
