#ifndef UTILITY_H_
#define UTILITY_H_

//メッセージボックス(Yes or No)
int MessageBoxYesNo(LPCTSTR lpText) noexcept;

//メッセージボックス(OK)
int MessageBoxOk(LPCTSTR lpText) noexcept;

//画面クリア処理関数
void ScreenClear() noexcept;

//ゲーム終了確認ウインドウ
void GameEndMessageBox();

//各種ショートカットキー
void ShortCutKey();

//タイトルムービー処理
void TitleMoviePlay();

#endif // !UTILITY_H_
