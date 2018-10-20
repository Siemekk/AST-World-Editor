#include "AST.h"
#include "CVobList.h"

CVobList::CVobList()
{
	m_arrVobs.DeleteList();
}

void CVobList::PickVob(zCVob* vob)
{
	if(!m_arrVobs.IsInList(vob))
		m_arrVobs.Insert(vob);
	else
		m_arrVobs.Remove(vob);
}

void CVobList::Process(CGizmo gzm)
{
	int nSize = m_arrVobs.GetNum();
	for(int i = 0; i < m_arrVobs.GetNum(); i++)
	{
		if(m_arrVobs[i])
		{
			// Draw BBox
			m_arrVobs[i]->bbox3D.Draw(zCOLOR(200, 50, 50, 255));

			if(nSize == 1)
			{
				gzm.DrawMove(m_arrVobs[i]);
			}
			else
			{
				gzm.DrawMarker(m_arrVobs[i]);
				//Draw gizmo at center point
			}
		}
	}
}

void CVobList::Clear()
{
	for(int i = m_arrVobs.GetNum(); i > 0; i--)
		m_arrVobs.RemoveIndex(i);
}