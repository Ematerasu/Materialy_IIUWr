using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;
using UnityEngine.SocialPlatforms.Impl;

public class ScoreScript : MonoBehaviour
{
    public TextMeshProUGUI scoreText;
    public GameObject GameOverUI;
    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        string multiplier = "";
        if (PlayerManager.instance.multiplier > 1 && !GameOverUI.activeSelf)
        {
            multiplier = "x" + PlayerManager.instance.multiplier.ToString();
        }
        string text = $"Diamonds: {PlayerManager.instance.diamondsCounter} {multiplier}";
        scoreText.SetText(text);
    }
}
