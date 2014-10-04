/*
 * Copyright 2014 Oliver Giles
 *
 * This file is part of SequelJoe. SequelJoe is licensed under the
 * GNU GPL version 3. See LICENSE or <http://www.gnu.org/licenses/>
 * for more information
 */
#ifndef _SEQUELJOE_SQLSCHEMAMODEL_H_
#define _SEQUELJOE_SQLSCHEMAMODEL_H_

#include "sqlmodel.h"
#include "tabledata.h"

class DbConnection;

class SqlSchemaModel : public SqlModel
{
    Q_OBJECT
public:
    explicit SqlSchemaModel(DbConnection &db, QString tableName, QObject *parent = 0);
    virtual ~SqlSchemaModel() {}

    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    virtual Qt::ItemFlags flags(const QModelIndex &index) const override;
    virtual bool deleteRows(QSet<int>) override;

    void select() override;

protected:
    virtual void selectComplete(TableData data) override;
    virtual bool columnIsBoolType(int col) const override;

protected slots:
    bool submit() override;

private:
    QString originalColumnName;
    QString tableName;
};

#endif // _SEQUELJOE_SQLSCHEMAMODEL_H_