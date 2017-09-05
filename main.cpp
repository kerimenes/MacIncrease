#include <QCoreApplication>
#include <QDebug>
#include <QByteArray>

int hexToInt(QString value);
QString increase(QString value);
QString increaseMac(QString start);

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	QStringList parameters = a.arguments();
	QString start = parameters.at(1);
	QString finish = parameters.at(2);

	bool status = true;
	QString mac = start;
	while(status) {
		 mac = increaseMac(mac);
		if(mac == finish) {
			status = false;
			break;
		}
		qDebug() << mac;
	}

	return 0;
}

QString increaseMac(QString start)
{
	QString mac;
	QStringList flds = start.split(":");
	QString mac1 = flds.at(0);
	QString mac2 = flds.at(1);
	QString mac3 = flds.at(2);
	QString mac4 = flds.at(3);
	QString mac5 = flds.at(4);
	QString mac6 = flds.at(5);
	mac6 = increase(mac6);
	if (mac6 == "ff") {
		mac6 = "00";
		mac5 = increase(mac5);
		if(mac5 == "ff") {
			mac5 = "00";
			mac4 = increase(mac4);
			if(mac4 == "ff") {
				mac4 = "00";
				mac3 = increase(mac3);
				if (mac3 == "ff") {
					mac3 = "00";
					mac2 = increase(mac2);
					if(mac2 == "ff") {
						mac2 = "00";
						mac1 = increase(mac1);
					}
				}
			}
		}
		if (mac6.size() == 1)
			mac6 = QString("0%1").arg(mac6);
		if (mac5.size() == 1)
			mac5 = QString("0%1").arg(mac5);
		if (mac4.size() == 1)
			mac4 = QString("0%1").arg(mac4);
		if (mac3.size() == 1)
			mac3 = QString("0%1").arg(mac3);
		if (mac2.size() == 1)
			mac2 = QString("0%1").arg(mac2);
		if (mac1.size() == 1)
			mac1 = QString("0%1").arg(mac1);
		mac = QString("%1:%2:%3:%4:%5:%6")
				.arg(mac1)
				.arg(mac2)
				.arg(mac3)
				.arg(mac4)
				.arg(mac5)
				.arg(mac6);
	} else {
		if (mac6.size() == 1)
			mac6 = QString("0%1").arg(mac6);
		if (mac5.size() == 1)
			mac5 = QString("0%1").arg(mac5);
		if (mac4.size() == 1)
			mac4 = QString("0%1").arg(mac4);
		if (mac3.size() == 1)
			mac3 = QString("0%1").arg(mac3);
		if (mac2.size() == 1)
			mac2 = QString("0%1").arg(mac2);
		if (mac1.size() == 1)
			mac1 = QString("0%1").arg(mac1);
		mac = QString("%1:%2:%3:%4:%5:%6")
				.arg(mac1)
				.arg(mac2)
				.arg(mac3)
				.arg(mac4)
				.arg(mac5)
				.arg(mac6);
	}
	return mac;

}

QString increase(QString value) {
	bool bStatus = false;
	int address = value.toInt(&bStatus, 16);
	address++;
	value = QString::number(address, 16);
	return value;
}

int hexToInt(QString value)
{
	bool bStatus = false;
	return value.toInt(&bStatus, 16);
}
