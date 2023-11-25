using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class highScoreScript : MonoBehaviour
{
    public TextMeshProUGUI highScoreText;
    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        if (PlayerManager.highestScore < PlayerManager.diamondsCounter)
        {
            PlayerManager.highestScore = PlayerManager.diamondsCounter;
            PlayerPrefs.SetInt("highscore", PlayerManager.highestScore);
        }
        string text = $"Highest score: {PlayerManager.highestScore}";
        highScoreText.SetText(text);
    }
}
