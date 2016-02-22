#include "GameBoard.h"

using namespace std;

GameBoard::GameBoard(int inWidth, int inHeight) throw(bad_alloc) :
	mWidth(inWidth), mHeight(inHeight)
{
	int i = 0;
	mCells = new GamePiece* [mWidth];

	try
	{
		for (i = 0; i < mWidth; i++)
			mCells[i] = new GamePiece[mHeight];
	}
	catch (...)
	{
		for (int j = 0; j < i; j++)
		{
			delete [] mCells[j];
		}
		delete [] mCells;
		mCells = nullptr;

		throw bad_alloc();
	}
}

GameBoard::GameBoard(const GameBoard& src) throw(bad_alloc)
{
	copyFrom(src);
}

GameBoard::~GameBoard() noexcept
{
	for (int i = 0; i < mWidth; i++)
	{
		delete [] mCells[i];
	}
	delete [] mCells;
	mCells = nullptr;
}

GameBoard& GameBoard::operator=(const GameBoard& rhs) throw(bad_alloc)
{
	if (this == &rhs)
	{
		return *this;
	}

	for (int i = 0; i < mWidth; i++)
	{
		delete [] mCells[i];
	}
	delete [] mCells;
	mCells = nullptr;

	copyFrom(rhs);

	return *this;
}

void GameBoard::copyFrom(const GameBoard& src) throw(bad_alloc)
{
	int i = 0;
	mWidth = src.mWidth;
	mHeight = src.mHeight;

	mCells = new GamePiece* [mWidth];

	try
	{
		for (i = 0; i < mWidth; i++)
		{
			mCells[i] = new GamePiece[mHeight];
		}
	}
	catch (...)
	{
		for (int j = 0; j < i; j++)
		{
			delete [] mCells[j];
		}
		delete [] mCells;
		mCells = nullptr;
		mWidth = mHeight = 0;
		throw bad_alloc();
	}

	for (i = 0; i < mWidth; i++)
	{
		for (int j = 0; j < mHeight; j++)
		{
			mCells[i][j] = src.mCells[i][j];
		}
	}
}

void GameBoard::setPieceAt(int x, int y, const GamePiece& inElem) throw(out_of_range)
{
	if (x < 0)
    throw out_of_range("GameBoard::setPieceAt: x-coordinate negative");
  if (x >= mWidth)
    throw out_of_range("GameBoard::setPieceAt: x-coordinate beyond width");
  if (y < 0)
    throw out_of_range("GameBoard::setPieceAt: y-coordinate negative");
  if (y >= mHeight)
    throw out_of_range("GameBoard::setPieceAt: y-coordinate beyond height");

  mCells[x][y] = inElem;
}

GamePiece& GameBoard::getPieceAt(int x, int y) throw(out_of_range)
{
  if (x < 0)
    throw out_of_range("GameBoard::getPieceAt: x-coordinate negative");
  if (x >= mWidth)
    throw out_of_range("GameBoard::getPieceAt: x-coordinate beyond width");
  if (y < 0)
    throw out_of_range("GameBoard::getPieceAt: y-coordinate negative");
  if (y >= mHeight)
    throw out_of_range("GameBoard::getPieceAt: y-coordinate beyond height");

  return mCells[x][y];
}

const GamePiece& GameBoard::getPieceAt(int x, int y) const throw(out_of_range)
{
  if (x < 0)
    throw out_of_range("GameBoard::getPieceAt const: x-coordinate negative");
  if (x >= mWidth)
    throw out_of_range("GameBoard::getPieceAt const: x-coordinate beyond width");
  if (y < 0)
    throw out_of_range("GameBoard::getPieceAt const: y-coordinate negative");
  if (y >= mHeight)
    throw out_of_range("GameBoard::getPieceAt const: y-coordinate beyond height");

  return mCells[x][y];
}
