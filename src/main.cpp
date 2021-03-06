#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <SQLiteCpp/SQLiteCpp.h>

using namespace std;


int main()
{
	try
	{
		// Open a database file
		SQLite::Database    db("movies.db");

		// Compile a SQL query, containing one parameter (index 1)
		SQLite::Statement   query(db, "SELECT * FROM MOVIES");

		// Loop to execute the query step by step, to get rows of result
		while (query.executeStep())
		{
			// Demonstrate how to get some typed column value
			int         id = query.getColumn(0);
			const char* value = query.getColumn(1);

			std::cout << "Id: " << id << " Name : " << value << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "exception: " << e.what() << std::endl;
	}
}
