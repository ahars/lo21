/*!
  * \file logMessage.h
  * \author Han Jia & Antoine Hars
  * \brief Déclaration des méthodes de la classe LogMessage.
  * Ce fichier contient la déclaration des méthodes de la classe LogMessage.
  */

/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: logMessage.h
 */

#include "logMessage.h"

/*!
  * \brief Constructeur
  * Constructeur de la classe LogMessage
  * \param parent correspond à l'adresse du parent.
  * \param criticite indice de l'importance du message.
  */
LogMessage::LogMessage(QString _msg, unsigned int _criticite) : msg(_msg), criticite(_criticite)
{
    time_t maintenant;

    time(& maintenant);
    date = * localtime(& maintenant);
}

QString LogMessage::toDateString(int i)
{
    QString a = "";
    if (i < 10 && i >= 0)
        a = "0";
    a.append(QString::number(i));
    return a;

}

/*!
 *  \brief Fonction permettant de retourner une chaine de caractère comportant les éléments du log.
 *  Fonction permettant de retourner une chaine de caractère comportant les éléments du log.
 *  \return Retourne les éléments du log sous forme de texte : |criticité| , date heure => message.
 */
std::string LogMessage::toString()
{
    QString tmp;

    tmp.append("|");
    tmp.append(toDateString(criticite));
    tmp.append("|, ");
    tmp.append(toDateString(date.tm_year + 1900));
    tmp.append("-");
    tmp.append(toDateString(date.tm_mon + 1));
    tmp.append("-");
    tmp.append(toDateString(date.tm_mday));
    tmp.append(" ");
    tmp.append(toDateString(date.tm_hour));
    tmp.append(":");
    tmp.append(toDateString(date.tm_min));
    tmp.append(":");
    tmp.append(toDateString(date.tm_sec));
    tmp.append(" => ");
    tmp.append(msg);
    return tmp.toStdString();
}
