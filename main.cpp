#include <vtkTriangle.h>
#include <vtkSmartPointer.h>
#include <vtkPoints.h>
#include <vtkLine.h>
#include <vtkCellArray.h>
#include <vtkPolyData.h>

using namespace std;

int main() {

  // Set up the array of points
  vtkSmartPointer<vtkPoints> points =
    vtkSmartPointer<vtkPoints>::New();

  vtkIdType p0_0_0 =
    points->InsertNextPoint(0, 0, 0);

  cout << "p0_0_0 = " << p0_0_0 << endl;

  vtkIdType p1_0_0 =
    points->InsertNextPoint(1, 0, 0);

  cout << "p1_0_0 = " << p1_0_0 << endl;

  vtkIdType p1_1_0 =
    points->InsertNextPoint(1, 1, 0);

  cout << "p1_1_0 = " << p1_1_0 << endl;
  
  vtkIdType p0_1_0 =
    points->InsertNextPoint(0, 1, 0);

  cout << "p0_1_0 = " << p0_1_0 << endl;

  // Create cells for lines
  vtkSmartPointer<vtkLine> l01 =
    vtkSmartPointer<vtkLine>::New();
  l01->GetPointIds()->SetId(0, p0_0_0);
  l01->GetPointIds()->SetId(1, p1_0_0);

  vtkSmartPointer<vtkLine> l13 =
    vtkSmartPointer<vtkLine>::New();
  l13->GetPointIds()->SetId(0, p1_0_0);
  l13->GetPointIds()->SetId(1, p0_1_0);

  vtkSmartPointer<vtkLine> l30 =
    vtkSmartPointer<vtkLine>::New();
  l30->GetPointIds()->SetId(0, p0_1_0);
  l30->GetPointIds()->SetId(1, p0_0_0);

  vtkSmartPointer<vtkLine> l23 =
    vtkSmartPointer<vtkLine>::New();
  l23->GetPointIds()->SetId(0, p1_1_0);
  l23->GetPointIds()->SetId(1, p0_1_0);
  
  // Add the cells to the lines cell array
  vtkSmartPointer<vtkCellArray> lines =
    vtkSmartPointer<vtkCellArray>::New();

  lines->InsertNextCell(l01);
  lines->InsertNextCell(l13);
  lines->InsertNextCell(l30);
  lines->InsertNextCell(l23);

  
}
