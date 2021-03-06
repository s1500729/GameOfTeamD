#pragma once

#include <Siv3D.hpp>
#include "Player.h"
#include "Action.h"
#include "PieceType.h"
#include "GameLib.h"

class Block
{
public:
	///<summary>
	/// デフォルトコンストラクタ
	///</summary>
	Block();

	///<summary>
	/// ピースを元にブロックを作成する
	///</summary>
	///<param name="pieces">Length*Lengthの二次元配列のピース</param>
	Block(Grid<PieceType> pieces);

	///<summary>
	/// デストラクタ
	///</summary>
	~Block();

public:
	///<summary>
	/// ブロックの色を取得する
	///</summary>
	Grid<Color> GetColor() const;

	///<summary>
	/// ブロックの各ピースを取得する
	///</summary>
	Array<Rect> GetAllPieces() const;

	Array<PieceType> GetPieces(int heigt) const;

	///<summary>
	/// ブロックを右に90度回転する
	///</summary>
	void TurnRight();

	///<summary>
	/// ブロックを左に90度回転する
	///</summary>
	void TurnLeft();

	///<summary>
	/// ブロックの左上の座標を設定する
	///</summary>
	void SetPos(int height, const Point &pos);

	/// <summary>
	/// ブロックの落ちるスピードを設定する
	/// </summary>
	/// <param name="speed">速度</param>
	void SetSpeed(int speed);

	///<summary>
	/// フィールド内のブロックのある高さを取得する
	///</summary>
	int GetHeight();

	Size GetSize();

	///<summary>
	/// ブロックをフィールドに応じて動かす
	///</summary>
	///<param name="p">動かす方向[Action::Left, Action::Right]のみ</param>
	void Move(Action action);

	///<summary>
	/// ブロックを描画する
	///</summary>
	///<param name="origin">パズルフィールドの原点</param>
	void Draw(Point origin) const;

	template <class Shape>
	bool Intersects(const Shape& shape) const;

	template <class Shape>
	bool Contains(const Shape& shape) const;

private:
	///<summary>
	/// ブロックの色データ
	///</summary>
	Grid<PieceType> m_pieces;

	///<summary>
	/// ブロックの左上の座標
	///</summary>
	Point m_pos;

	int m_height;
	bool m_is_black;
	int m_speed;
};

template<class Shape>
inline bool Block::Intersects(const Shape & shape) const
{
	for (auto piece : GetAllPieces())
	{
		if (piece.intersects(shape))
		{
			return true;
		}
	}

	return false;
}

template<class Shape>
inline bool Block::Contains(const Shape & shape) const
{
	for (auto piece : GetAllPieces())
	{
		if (piece.contains(shape))
		{
			return true;
		}
	}

	return false;
}
