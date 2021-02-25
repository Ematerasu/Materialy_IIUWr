<?php

namespace App\Entity;

use Symfony\Component\Validator\Constraints as Assert;

class Przelew
{
    /**
     * @Assert\NotBlank(message="Pole nie może być puste")
     * 
     */
    private $ID;

    /**
     * @Assert\NotBlank(message="Pole nie może być puste")
     * @Assert\Length(
     *     min = 32,
     *     max = 32,
     *     exactMessage = "Numer konta musi zawierac 26 cyfr"
     *)
     *  @Assert\Regex("/([0-9]{2})[[:space:]](1234 9876)([[:space:]]([0-9]{4})){4}$/") 
     *
     */
    private $KontoOd;

    /**
     * @Assert\NotBlank(message="Pole nie może być puste")
     * @Assert\Length(
     *     min = 32,
     *     max = 32,
     *     exactMessage = "Numer konta musi zawierac 26 cyfr"
     *)
     *  @Assert\Regex("/([0-9]{2})[[:space:]](1234 9876)([[:space:]]([0-9]{4})){4}$/") 
     * 
     */
    private $KontoDo;

    /**
     * @Assert\NotBlank(message="Pole nie może być puste")
     * @Assert\Length(
     *     min = 5,
     *     max = 50,
     *     minMessage = "Za krotkie imie i nazwisko",
     *     maxMessage = "Limit znakow"
     *)
     * 
     */
    private $ImieNazwisko;

    /**
     * @Assert\NotBlank(message="Pole nie może być puste")
     * @Assert\Length(
     *     min = 2,
     *     max = 50,
     *     minMessage = "Za krotka nazwa ulicy",
     *     maxMessage = "Limit znakow"
     *)
     * 
     */
    private $Ulica;

    /**
     * @Assert\NotBlank(message="Pole nie może być puste")
     * @Assert\Length(
     *     min = 2,
     *     max = 50,
     *     minMessage = "Za krotka nazwa miejscowosci",
     *     maxMessage = "Limit znakow"
     *)
     * 
     */
    private $Miejscowosc;

    /**
     * @Assert\NotBlank(message="Pole nie może być puste")
     * @Assert\Regex("/(([0-9]){2})(-)([0-9]{3})/")
     * 
     */
    private $KodPocztowy;
    /**
     * @Assert\NotBlank(message="Pole nie może być puste")
     * @Assert\Positive
     * 
     */
    private $Kwota;

    /**
     * @Assert\NotBlank(message="Pole nie może być puste")
     * @Assert\Length(
     *     max = 100,
     *     maxMessage = "Limit znakow"
     *)
     * 
     */
    private $Tytulem;

    /**
     * @Assert\Date
     * @var string A "d-m-Y" formatted value
     */
    private $DataWykonania;


    /**
     * Set ID
     *
     * @param string $ID
     */
    public function setID($ID)
    {
        $this->ID = $ID;
    }

    /**
     * Get ID
     *
     * @return string 
     */
    public function getID()
    {
        return $this->ID;
    }

    /**
     * Set KontoOd
     *
     * @param string $KontoOd
     */
    public function setKontoOd($KontoOd)
    {
        $this->KontoOd = $KontoOd;
    }

    /**
     * Get KontoOd
     *
     * @return string 
     */
    public function getKontoOd()
    {
        return $this->KontoOd;
    }

    /**
     * Set KontoDo
     *
     * @param string $KontoDo
     */
    public function setKontoDo($KontoDo)
    {
        $this->KontoDo = $KontoDo;
    }

    /**
     * Get KontoDo
     *
     * @return string 
     */
    public function getKontoDo()
    {
        return $this->KontoDo;
    }

    /**
     * Set ImieNazwisko
     *
     * @param string $ImieNazwisko
     */
    public function setImieNazwisko($ImieNazwisko)
    {
        $this->ImieNazwisko = $ImieNazwisko;
    }

    /**
     * Get ImieNazwisko
     *
     * @return string 
     */
    public function getImieNazwisko()
    {
        return $this->ImieNazwisko;
    }

    /**
     * Set Ulica
     *
     * @param string $Ulica
     */
    public function setUlica($Ulica)
    {
        $this->Ulica = $Ulica;
    }

    /**
     * Get Ulica
     *
     * @return string 
     */
    public function getUlica()
    {
        return $this->Ulica;
    }

    /**
     * Set Miejscowosc
     *
     * @param string $Miejscowosc
     */
    public function setMiejscowosc($Miejscowosc)
    {
        $this->Miejscowosc = $Miejscowosc;
    }

    /**
     * Get Miejscowosc
     *
     * @return string 
     */
    public function getMiejsowosc()
    {
        return $this->Miejscowosc;
    }

    /**
     * Set KodPocztowy
     *
     * @param string $KodPocztowy
     */
    public function setKodPocztowy($KodPocztowy)
    {
        $this->KodPocztowy = $KodPocztowy;
    }

    /**
     * Get KodPocztowy
     *
     * @return string 
     */
    public function getKodPocztowy()
    {
        return $this->KodPocztowy;
    }

    /**
     * Set Kwota
     *
     * @param string $Kwota
     */
    public function setKwota($Kwota)
    {
        $this->Kwota = $Kwota;
    }

    /**
     * Get Kwota
     *
     * @return string 
     */
    public function getKwota()
    {
        return $this->Kwota;
    }

    /**
     * Set Tytulem
     *
     * @param string $Tytulem
     */
    public function setTytulem($Tytulem)
    {
        $this->Tytulem = $Tytulem;
    }

    /**
     * Get Tytulem
     *
     * @return string 
     */
    public function getTytulem()
    {
        return $this->Tytulem;
    }

    /**
     * Set DataWykonania
     *
     * @param string $DataWykonania
     */
    public function setDataWykonania($DataWykonania)
    {
        $this->DataWykonania = $DataWykonania;
    }

    /**
     * Get DataWykonania
     *
     * @return string 
     */
    public function getDataWykonania()
    {
        return $this->DataWykonania;
    }




}