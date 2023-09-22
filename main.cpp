#include <iostream>
#include <vector>
#include <iomanip>
#include "Point.h"

using namespace std;

void horse_move(vector<Point>& visited_point, const int size)
{
	static const vector<Point> move{Point(-1, -2), Point(1, -2), Point(-2, -1), Point(2, -1), Point(-2, 1), Point(2, 1), Point(-1, 2), Point(1, 2)};

	Point end_point(0,0);
	bool moved = true;
	while (moved && visited_point.size() < size * size)
	{
		moved = false;
		for (auto m : move)
		{
			end_point = visited_point[visited_point.size() - 1];
			end_point += m;

			if (std::find(visited_point.begin(), visited_point.end(), end_point) == visited_point.end()
				&& end_point.isValid(size))
			{
				visited_point.push_back(end_point);
				horse_move(visited_point, size);

				if (visited_point.size() != size * size)
					visited_point.pop_back();
				else
				{
					moved = true;
					break;
				}
			}
		}
	}

}

void horse_move(const Point& start, const int size = 8)
{
	vector<Point> visited_point{start};

	horse_move(visited_point, size);

	if (visited_point.size() == size * size)
		for (int i = 0; i < visited_point.size(); ++i)
			cout << "index:" << setw(2) << i << ": the move is x:" << visited_point[i].getX() << " and y: " << visited_point[i].getY() << endl;
	else
		cout << "Not found the path to visit all chess points." << endl;
}

int main()
{
	
	horse_move(Point(0, 0), 3);
	horse_move(Point(0, 0), 8);
	return 0;
}