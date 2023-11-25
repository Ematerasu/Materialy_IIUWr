using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using TMPro;

public class GameManager : MonoBehaviour
{
    bool gameEnded = false;
    public GameObject gameOverText;

    private void Start()
    {
        Screen.SetResolution(1469, 732, false);
    }
    public void EndGame()
    {
        if (!gameEnded)
        {
            gameEnded = true;
            gameOverText.SetActive(true);
            Invoke("Restart", 1f);
        }

    }

    void Restart()
    {
        SceneManager.LoadScene(SceneManager.GetActiveScene().name);
    }

    public void FinishGame()
    {
    }
}
