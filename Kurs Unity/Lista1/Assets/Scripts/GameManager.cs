using UnityEngine;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    bool gameEnded = false;

    public GameObject completeLevelUI;

    public void EndGame()
    {
        if (!gameEnded)
        {
            gameEnded = true;
            Invoke("Restart", 1f);
        }

    }

    void Restart()
    {
        SceneManager.LoadScene(SceneManager.GetActiveScene().name);
    }

    public void FinishGame()
    {
        completeLevelUI.SetActive(true);
    }
}
