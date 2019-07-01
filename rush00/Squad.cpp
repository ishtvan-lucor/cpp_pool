#include "Squad.hpp"

Squad::Squad() : _count(0), _score(0), _list(nullptr){};

Squad::~Squad()
{

	while (this->_list)
	{
		t_list *tmp = this->_list;
		delete this->_list->elem;
		delete this->_list;
		this->_list = tmp->next;
	}
};

Squad::Squad(Squad &other)
{
	*this = other;
}

Squad::Squad(const Squad &other)
{
	*this = other;
}

//Squad &Squad::operator=(Squad &other)
//{
//	this->_count = other._count;
//	this->_list = other._list;
//
//	return *this;
//}

Squad &Squad::operator=(const Squad &other)
{
	this->_count = other._count;
	this->_list = other._list;

	return *this;
}

//int Squad::getCount() const
//{
//	return this->_count;
//};

int Squad::push(AGameObject *elem)
{
	if (this->_list == nullptr)
	{
		this->_list = new t_list;
		this->_list->elem = elem;
		this->_list->next = nullptr;
		this->_count += 1;
	}
	else
	{
		t_list *tmp = this->_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new t_list;
		tmp->next->elem = elem;
		tmp->next->next = nullptr;
		this->_count += 1;
	}
	return this->_count;
};

AGameObject *Squad::getGameObject(int id) const
{

	if (id > this->_count)
		return nullptr;
	int i = -1;
	t_list *tmp = this->_list;
	while (id < this->_count && ++i < id)
		tmp = tmp->next;
	return tmp->elem;
};

void Squad::moveObjects(Vec2 dir, float f)
{
	t_list *tmp;

	tmp = this->_list;
	while (tmp)
	{
		tmp->elem->move(dir, f);
		tmp = tmp->next;
	}
}

void Squad::displayObjects()
{
	t_list *tmp;

	tmp = this->_list;
	while (tmp)
	{
		tmp->elem->display();
		tmp = tmp->next;
	}
	 this->cleanEdges();
}

void Squad::filterCollision(Vec2 target)
{
	t_list *tmp;
	int radius = 3;

	int i = 0;
	tmp = this->_list;
	while (tmp)
	{
		if (target.checkRadius(tmp->elem->getPos(), radius))
		{
			this->deleteSpecificItem(i);
			this->_score++;
		}
		i++;
		tmp = tmp->next;
	}
}

bool Squad::playerCollision(Vec2 target)
{
	t_list *tmp;
	int radius = 2;

	int i = 0;
	tmp = this->_list;
	while (tmp)
	{
		if (target.checkRadius(tmp->elem->getPos(), radius))
			return (true);
		i++;
		tmp = tmp->next;
	}
	return (false);
}

void Squad::generateObjects(int amount, int width, std::string type)
{
	int alreadyExist[amount];
	for (int i = 0; i < amount; i++)
	{
		int x;

		srand(clock());
		x = 2 + (rand() % width - 2);
		for (int j = 0; j < i; j++)
		{
			if (x == alreadyExist[j])
			{
				x = (x + 1) % width;
				j = -1;
			}
		}
		alreadyExist[i] = x;
		if (type == "enemy")
		{
			Enemy *newEnemy = new Enemy(x, 0);
			this->push(newEnemy);
		}
		else
		{
			Star *newStar = new Star(x, 0);
			this->push(newStar);
		}
	}
}

t_list *Squad::getGameObjectList(int id)
{

	if (id > this->_count)
		return nullptr;
	int i = -1;
	t_list *tmp = this->_list;
	while (id < this->_count && ++i < id)
		tmp = tmp->next;
	return tmp;
};

void Squad::deleteObj(int id)
{
	t_list *temp;

	if (id == 0)
	{
		temp = this->_list;
		this->_list = this->_list->next;
		delete temp->elem;
		delete temp;
		_count--;
	}
	else if (id == (_count - 1))
	{
		delete (this->getGameObject(id));
		delete (this->getGameObjectList(id));
		this->getGameObjectList(id - 1)->next = nullptr;
		_count--;
	}
	else
	{
		temp = this->getGameObjectList(id);
		this->getGameObjectList(id - 1)->next = temp->next;
		delete temp->elem;
		delete temp;
		_count--;
	}
}

int Squad::getScore(void) const
{
	return (this->_score);
}

void Squad::setMovementEdge(int xMin, int yMin, int xMax, int yMax)
{
	this->_edgeMin = Vec2(xMin, yMin);
	this->_edgeMax = Vec2(xMax, yMax);
}

int Squad::deleteSpecificItem(int val)
{
	t_list *tmp = this->_list;
	t_list *prev = nullptr;

	int i = 0;
	while (i != val && tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
		i++;
	}

	if (i == val)
	{
		if (prev)
		{
			prev->next = tmp->next;
		}
		else
		{
			this->_list = tmp->next;
		}
		i++;
		delete tmp->elem;
		delete tmp;
		return val;
	}
	return -1;
}

void Squad::cleanEdges()
{
	t_list *tmp;
	t_list *i;

	while (this->_list && this->_list->elem->getPos().outOfEdge(this->_edgeMin, this->_edgeMax))
	{
		tmp = this->_list;
		this->_list = this->_list->next;
		delete tmp->elem;
		delete tmp;
	}
	i = this->_list;
	while (i && i->next)
	{
		if (i->elem->getPos().outOfEdge(this->_edgeMin, this->_edgeMax))
		{
			tmp = i->next;
			i->next = tmp->next;
			delete tmp->elem;
			delete tmp;
		}
		if (i->next)
			i = i->next;
	}
}

void Squad::rm(t_list **begin_list)
{
	t_list *temp;

	if (*begin_list)
	{
		if ((*begin_list)->elem->getPos().outOfEdge(this->_edgeMin, this->_edgeMax))
		{
			temp = *begin_list;
			*begin_list = (*begin_list)->next;
			free(temp);
			this->rm(begin_list);
		}
		else
			this->rm(&(*begin_list)->next);
	}
}