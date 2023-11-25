using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class PlayerScore : MonoBehaviour
{
    public Transform player;
    public TextMeshProUGUI scoreText;
    public static int score;
    // Start is called before the first frame update
    void Start()
    {
        score = 0;
    }

    // Update is called once per frame
    void Update()
    {
        string text = string.Format("Score: {0}", score);
        scoreText.SetText(text);
    }

    public static void IncrementScore()
    {
        score++;
    }

    public static int GetScore()
    {
        return score;
    }
}
