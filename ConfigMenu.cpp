// Config Menu Source

#include "DxLib.h"
#include "ConstantExpressionVariable.h"
#include "Utility.h"
#include "ConfigMenu.h"
#include <thread>
#include <chrono>

ConfigData_t ConfigData = {
	/*bgm_vol               :*/100,
	/*bgm_vol_count         :*/10,
	/*se_vol                :*/100,
	/*se_vol_count          :*/10,
	/*skip_speed            :*/100,
	/*skip_speed_count      :*/10,
	/*auto_speed            :*/100,
	/*auto_speed_count      :*/10,
	/*string_speed          :*/100,
	/*string_speed_count    :*/10,
	/*mouse_key_move        :*/1
};

namespace {

	static constexpr const char* ConfigMenuItem[] = {
		"ＢＧＭ音量", "ＳＥ音量", "オート速度", "スキップ速度", "文字描画速度", "描画方法", "マウス/キー操作", "戻る"
	};

	//コンフィグ画面描画
	void ConfigMenuDraw(std::int32_t& cursor_y) {

		//各項目の描画
		for (std::int32_t i = 0; i < 8; i++)
			DxLib::DrawString(save_name_pos_x, game_menu_base_pos_y * (i + 1), ConfigMenuItem[i], 255);

		DxLib::DrawString(save_name_pos_x - cursor_move, cursor_y, "■", 255);

		DxLib::DrawFormatString(save_name_pos_x + cursor_move * 5, game_menu_base_pos_y, 255, "%d", ConfigData.bgm_vol);
		DxLib::DrawFormatString(save_name_pos_x + cursor_move * 5, game_menu_base_pos_y * 2, 255, "%d", ConfigData.se_vol);
	}

	//コンフィグ画面キー操作
	void ConfigMenuKeyMove(std::int32_t& cursor_y) {
		if (DxLib::CheckHitKey(KEY_INPUT_DOWN) == 1)
			cursor_y = (game_menu_base_pos_y * 8 == cursor_y) ? game_menu_base_pos_y : cursor_y + cursor_move;

		if (DxLib::CheckHitKey(KEY_INPUT_UP) == 1)
			cursor_y = (game_menu_base_pos_y == cursor_y) ? game_menu_base_pos_y * 8 : cursor_y - cursor_move;

		std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));
	}

	//BGM音量調節
	void BackGroundMusicVolChange() {
		if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
			std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));

			ConfigData.bgm_vol += 10;
			ConfigData.bgm_vol_count += 1;

			if (ConfigData.bgm_vol_count >= 10) {
				ConfigData.bgm_vol = 100;
				ConfigData.bgm_vol_count = 10;
			}
		}

		if (CheckHitKey(KEY_INPUT_LEFT) == 1) {
			std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));

			ConfigData.bgm_vol -= 10;
			ConfigData.bgm_vol_count -= 1;

			if (ConfigData.bgm_vol_count <= 0) {
				ConfigData.bgm_vol = 0;
				ConfigData.bgm_vol_count = 0;
			}
		}
	}

	//SE音量調節
	void SoundEffectVolChange() {
		if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {
			std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));

			ConfigData.se_vol += 10;
			ConfigData.se_vol_count += 1;

			if (ConfigData.se_vol_count >= 10) {
				ConfigData.se_vol = 100;
				ConfigData.se_vol_count = 10;
			}
		}

		if (CheckHitKey(KEY_INPUT_LEFT) == 1) {
			std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));

			ConfigData.se_vol -= 10;
			ConfigData.se_vol_count -= 1;

			if (ConfigData.se_vol_count <= 0) {
				ConfigData.se_vol = 0;
				ConfigData.se_vol_count = 0;
			}
		}
	}

	//コンフィグ画面選択処理
	void ConfigMenuSelect(std::int32_t& cursor_y, std::int32_t& ConfigFlag) {

		if (game_menu_base_pos_y == cursor_y)
			BackGroundMusicVolChange();

		if (game_menu_base_pos_y * 2 == cursor_y)
			SoundEffectVolChange();

		if (game_menu_base_pos_y * 8 == cursor_y && DxLib::CheckHitKey(KEY_INPUT_RETURN) == 1) {
			if (IDYES == MessageBoxYesNo("戻りますか？")) {
				ConfigFlag = 0;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(wait_key_task_time));
		}
	}
}

//コンフィグ画面ループ
void ConfigMenuLoop() {

	std::int32_t ConfigFlag = 1;

	std::int32_t config_y = game_menu_base_pos_y;

	while (ConfigFlag == 1) {
		ScreenClear();
		ConfigMenuDraw(config_y);
		ConfigMenuKeyMove(config_y);
		ConfigMenuSelect(config_y, ConfigFlag);
	}
}
