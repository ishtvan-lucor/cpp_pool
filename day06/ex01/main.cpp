//
// Created by Ishtvan KOLOSHYNSKY on 2019-07-04.
//

#include <iostream>
#define ALPHANUMERICAL 36

struct Data
{
	std::string	s1;
	int			n;
	std::string	s2;
};

void	*serialize( void )
{
	srand(clock());
	std::string	alphanumericCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	char		*serializationData = new char[20];
	int			randNumber = rand();

	for (int i  = 0; i < 8; i++)
	{
		serializationData[i] = alphanumericCharacters[rand() % ALPHANUMERICAL];
		serializationData[i + 12] = alphanumericCharacters[rand() % ALPHANUMERICAL];
	}
	*(reinterpret_cast<int *>(serializationData + 8)) = randNumber;

	return (reinterpret_cast<void *>(serializationData));
}

Data	*deserialize( void * raw )
{
	Data	*deserializeData = new Data();
	char	*serializedData = reinterpret_cast<char *>(raw);

	deserializeData->s1 = std::string(serializedData, 8);
	deserializeData->s2 = std::string((serializedData + 12), 8);
	deserializeData->n = *(reinterpret_cast<int*>(serializedData + 8));

	return deserializeData;
}

int main( void )
{
	Data	*secretData;

	secretData = deserialize(serialize());
	std::cout << "s1 = " << secretData->s1 << std::endl;
	std::cout << "n = " << secretData->n << std::endl;
	std::cout << "s2 = " << secretData->s2 << std::endl;
}