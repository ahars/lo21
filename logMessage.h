/*!
 * \file logMessage.h
 * \brief Fichier header de la class LogMessage
 * \author Han Jia & Antoine Hars
 */

#ifndef LOGMESSAGE_H
#define LOGMESSAGE_H

#include <QString>
#include <string>
#include <ctime>

/*! \class LogMessage
 * \brief classe permetant de creer un message de log.
 *
 *  classe permetant de creer un message de log.
 */
class LogMessage
{
private:
    QString msg; // Message du log.
    unsigned int criticite; // Criticité du log
    struct tm date; // date du log.

    /*!
     *  \brief Fonction permettant de retourner une chaine de caractère comportant un entier.
     *  Fonction permettant de retourner une chaine de caractère comportant un entier.
     *  \return Retourne l'entier sous forme de QString. avec au minimum deux chiffres.
     */
    QString toDateString(int i);

public:
    /*!
     *  \brief Constructeur
     *  Constructeur de la classe LogMessage
     *  \param parent correspond à l'adresse du parent.
     * \param criticite indice de l'importance du message.
     */
    LogMessage(QString msg, unsigned int criticite);

    /*!
     *  \brief Fonction permettant de retourner une chaine de caractère comportant les éléments du log.
     *  Fonction permettant de retourner une chaine de caractère comportant les éléments du log.
     *  \return Retourne les éléments du log sous forme de texte : |criticité| , date heure => message.
     */
    std::string toString();
};

#endif // LOGMESSAGE_H
