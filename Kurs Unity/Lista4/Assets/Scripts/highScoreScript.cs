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
        if (PlayerManager.instance.highestScore < PlayerManager.instance.diamondsCounter)
        {
            PlayerManager.instance.highestScore = PlayerManager.instance.diamondsCounter;
            PlayerPrefs.SetInt("highscore", PlayerManager.instance.highestScore);
        }
        string text = $"Highest score: {PlayerManager.instance.highestScore}";
        highScoreText.SetText(text);
    }
}
