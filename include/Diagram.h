#ifndef _DIAGRAM_H_
#define _DIAGRAM_H_

#include "../src/MemoryPool/C-11/MemoryPool.h"
//#include "../src/MemoryPool/C-98/MemoryPool.h" //You will need to use this version instead of the one above if your compiler doesn't handle C++11's noexcept operator
#include "Edge.h"
#include "Cell.h"
#include <set>

struct BoundingBox;
class Diagram {
public:
	std::vector<Cell*> cells;
	std::vector<Edge*> edges;
	std::vector<sf::Vector2<double>*> vertices;

	void printDiagram();
private:
	friend class VoronoiDiagramGenerator;

	std::set<Cell*> tmpCells;
	std::set<Edge*> tmpEdges;
	std::set<sf::Vector2<double>*> tmpVertices;

	MemoryPool<Cell> cellPool;
	MemoryPool<Edge> edgePool;
	MemoryPool<HalfEdge> halfEdgePool;
	MemoryPool<sf::Vector2<double>> vertexPool;

	sf::Vector2<double>* createVertex(double x, double y);
	Cell* createCell(sf::Vector2<double> site);
	Edge* createEdge(Site* lSite, Site* rSite, sf::Vector2<double>* vertA, sf::Vector2<double>* vertB);
	Edge* createBorderEdge(Site* lSite, sf::Vector2<double>* vertA, sf::Vector2<double>* vertB);

	bool connectEdge(Edge* edge, BoundingBox bbox);
	bool clipEdge(Edge* edge, BoundingBox bbox);
	void clipEdges(BoundingBox bbox);
	void closeCells(BoundingBox bbox);
	void finalize();
};

#endif