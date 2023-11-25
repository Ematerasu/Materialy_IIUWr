using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class ButtonHandler : MonoBehaviour
{
    public void LoadGame()
    {
        SceneManager.LoadScene("Game");
    }

    public void LoadSettings()
    {
        SceneManager.LoadScene("Settings");
    }

    public void LowSetting()
    {
        PlayerPrefs.SetInt("settings", 3);
        SceneManager.LoadScene("MainMenu");
    }

    public void MediumSetting()
    {
        PlayerPrefs.SetInt("settings", 4);
        SceneManager.LoadScene("MainMenu");
    }

    public void HighSetting()
    {
        PlayerPrefs.SetInt("settings", 5);
        SceneManager.LoadScene("MainMenu");
    }

    public void ReturnToMenu()
    {
        SceneManager.LoadScene("MainMenu");
    }

    public void QuitGame()
    {
        Application.Quit();
    }
}
