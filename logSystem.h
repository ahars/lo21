/*!
  * \file logSystem.h
  * \brief Fichier header de la classe LogSystem.
  * \author Han Jia & Antoine Hars
  */

/* UV: LO21 - projet
 * Sujet: Calculatrice à notation polonaise inversée
 * Auteurs: Han Jia & Antoine Hars
 * File: logSystem.h
 */

#ifndef LOGSYSTEM_H
#define LOGSYSTEM_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <iostream>
#include "logMessage.h"

/*! \class LogSystem
 * \brief classe permettant de gerer les logs.
 *  La classe permetant de gerer les logs.
 */
class LogSystem
{
private:
    /*!
     *  \brief Constructeur
     *  Constructeur de la classe LogSystem
     */
    explicit LogSystem(){}

    /*!
     *  \brief Constructeur de recopie
     *  Constructeur de recopie la classe LogSystem
     */
    LogSystem(LogSystem &){}

    /*!
     *  \brief Destructeur
     *  Destructeur de la classe LogSystem
     */
    ~LogSystem(){}

public:

    /*!
     *  \brief Fonction permetant d'ajouter un message de log.
     *  Fonction permetant d'ajouter un message de log.
     *  \param log log a gérer.
     */
    static void add(LogMessage log);
    /*!
     *  \brief Fonction permetant d'ajouter un message de log.
     *  Fonction permetant d'ajouter un message de log.
     *  \param msg Message a gérer.
     *  \param criticite Criticite du message.
     */
    static void add(QString msg, unsigned int criticite);

};

#endif // LOGSYSTEM_H
