#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    lienzo = QPixmap(500,500);
    this->dibujar();

    ui->outCuadro->setPixmap(lienzo);

}

Principal::~Principal()
{
    delete ui;
}

void Principal::dibujar()
{
    lienzo.fill(Qt::white);

    QPainter painter(&lienzo);

    int x = 30;
    int graf1 = 4*nota1;
    int graf2 = 4*nota2;
    int graf3 = 4*nota3;
    int promedio = 4*((nota1 + nota2 + nota3) / 3);


    // Crear un pincel para los bordes
    QPen pincel;
    pincel.setWidth(5);
    pincel.setColor(Qt::red);
    pincel.setJoinStyle(Qt::MiterJoin);

    // Establecer el pincel al "pintor"
    painter.setPen(pincel);

    // Dibujar primera barra
    painter.drawRect(x+50,(400- graf1+50),100,graf1);

    // Crear un objeto color para el relleno
    QColor colorRelleno(190,120,162);
    // Crear otro objeto color para el borde
    QColor colorBorde(78,3,48);
    //Crear color para la linea
    QColor colorLinea(0,0,0);

    // Cambiar el color del pincel
    pincel.setColor(colorBorde);

    // Volver a establecer el pincel al "pintor"
    painter.setPen(pincel);

    // Establecer el color al brush (relleno)
    painter.setBrush(colorRelleno);

    // Dibujar segunda barra
    painter.drawRect(x+170,(400-graf2+50), 100, graf2);

    // Creando los colores de la tercera barra
    QColor cRellenoBarra3(253, 253, 115);
    QColor cBordeBarra3(174, 174, 51);

    // Estableciendo colores al puncel y al painter
    pincel.setColor(cBordeBarra3);
    painter.setPen(pincel);
    painter.setBrush(cRellenoBarra3);

    // Dibujar tercera barra
    painter.drawRect(x+290,(400-graf3+50),100,graf3);
    //Cambiar color del pincel
    pincel.setColor(colorLinea);

    // Volver a establecer el pincel al "pintor"
    painter.setPen(pincel);

    //Dibujar linea
    painter.drawLine(x+50, (400-promedio+50), x+390, (400-promedio+50));

}


void Principal::on_actionGuardar_triggered()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(
                this,"Guardar imagen",QString(),"Imagenes (*.png)");
    if (!nombreArchivo.isEmpty()){
        if (lienzo.save(nombreArchivo))
            QMessageBox::information(this,"Guardar imagen","Archivo guarado en: " + nombreArchivo);
        else
            QMessageBox::warning(this,"Guardar imagen","No se pudo guardar el archivo");
    }
}



void Principal::on_spinBox_valueChanged(int arg1)
{
    nota1 = arg1;
    dibujar();
    ui->outCuadro->setPixmap(lienzo);

}


void Principal::on_spinBox_2_valueChanged(int arg1)
{

    nota2 = arg1;
    dibujar();
    ui->outCuadro->setPixmap(lienzo);

}


void Principal::on_spinBox_3_valueChanged(int arg1)
{

    nota3 = arg1;
    dibujar();
    ui->outCuadro->setPixmap(lienzo);

}

