/*
 * FUN_0042402c at 0042402c
 * undefined __register FUN_0042402c(int * param_1)
 * Address ranges: 0042402c-004240d3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042402c(int *param_1)

{
  HDC hdc;
  HGDIOBJ pvVar1;
  int iVar2;
  int iVar3;
  LONG LVar4;
  tagTEXTMETRICA local_7c;
  tagTEXTMETRICA local_44;
  
  hdc = GetDC((HWND)0x0);
  GetTextMetricsA(hdc,&local_7c);
  pvVar1 = (HGDIOBJ)FUN_004176e4(param_1[0x16]);
  pvVar1 = SelectObject(hdc,pvVar1);
  GetTextMetricsA(hdc,&local_44);
  SelectObject(hdc,pvVar1);
  ReleaseDC((HWND)0x0,hdc);
  if (*PTR_DAT_0047c7a0 == '\0') {
    LVar4 = local_7c.tmHeight;
    if (local_44.tmHeight < local_7c.tmHeight) {
      LVar4 = local_44.tmHeight;
    }
    iVar2 = GetSystemMetrics(6);
    if (LVar4 < 0) {
      LVar4 = LVar4 + 3;
    }
    iVar2 = iVar2 * 4 + (LVar4 >> 2);
  }
  else {
    if ((char)param_1[0x4e] == '\0') {
      iVar3 = 6;
    }
    else {
      iVar3 = 8;
    }
    iVar2 = GetSystemMetrics(6);
    iVar2 = iVar2 * iVar3;
  }
  FUN_0043eed0(param_1,local_44.tmHeight + iVar2);
  return;
}

