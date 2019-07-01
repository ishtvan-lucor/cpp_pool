#ifndef SQUAD_HPP
#define SQUAD_HPP

#include "Enemy.hpp"
#include "Star.hpp"
#include "ISquad.hpp"

typedef struct s_list
{
	AGameObject *elem;
	struct s_list *next;
} t_list;

class Squad : public ISquad
{
  private:
	int _count;
	int _score;
	t_list *_list;
	Vec2 _edgeMin;
	Vec2 _edgeMax;

  public:
	Squad(void);
	virtual ~Squad();
	Squad(const Squad &);
	Squad(Squad &);
	//Squad &operator=(Squad &);
	Squad &operator=(const Squad &);

	//virtual int getCount() const;
	virtual AGameObject *getGameObject(int) const;
	virtual int push(AGameObject *);
	void generateObjects(int, int, std::string);
	void moveObjects(Vec2 dir, float f);
	void displayObjects();
	void deleleObj(int id);
	t_list *getGameObjectList(int);
	void deleteObj(int id);
	void filterCollision(Vec2);
	bool playerCollision(Vec2 target);
	int getScore(void) const;
	int deleteSpecificItem(int);
	void setMovementEdge(int xMin, int yMin, int xMax, int yMax);
	void cleanEdges();
	void rm(t_list **begin_list);
};

#endif
