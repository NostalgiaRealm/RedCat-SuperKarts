/*
 * FUN_0045c174 at 0045c174
 * undefined FUN_0045c174(void)
 * Address ranges: 0045c174-0045c295
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045c174(int *param_1,char param_2)

{
  char cVar1;
  int *piVar2;
  byte extraout_DL;
  
  piVar2 = FUN_0040320c(param_1,param_2);
  ShowWindow((HWND)piVar2[0x2c],9);
  ShowWindow((HWND)piVar2[0x2d],9);
  if ((int *)piVar2[0x23] != (int *)0x0) {
    FUN_00402eac((int *)piVar2[0x23]);
  }
  if (piVar2[0x26] == 0) goto LAB_0045c204;
  cVar1 = FUN_0045bba8(piVar2[0x1f]);
  if (cVar1 == '\x02') {
LAB_0045c1cb:
    FUN_00457918();
  }
  else {
    cVar1 = FUN_0045bba8(piVar2[0x1f]);
    if (cVar1 == '\x04') goto LAB_0045c1cb;
  }
  cVar1 = FUN_0045bba8(piVar2[0x1f]);
  if (cVar1 == '\x01') {
LAB_0045c1ee:
    FUN_00457b34(piVar2[0x26]);
  }
  else {
    cVar1 = FUN_0045bba8(piVar2[0x1f]);
    if (cVar1 == '\x03') goto LAB_0045c1ee;
  }
  FUN_00402eac((int *)piVar2[0x26]);
LAB_0045c204:
  if ((int *)piVar2[0x20] != (int *)0x0) {
    FUN_00402eac((int *)piVar2[0x20]);
  }
  if ((int *)piVar2[0x1f] != (int *)0x0) {
    FUN_00402eac((int *)piVar2[0x1f]);
  }
  if (piVar2[0x25] != 0) {
    FUN_0045805c(piVar2[0x25]);
    FUN_00402eac((int *)piVar2[0x25]);
  }
  if ((int *)piVar2[0x21] != (int *)0x0) {
    FUN_00402eac((int *)piVar2[0x21]);
  }
  if ((int *)piVar2[0x22] != (int *)0x0) {
    FUN_00402eac((int *)piVar2[0x22]);
  }
  if ((int *)piVar2[0x24] != (int *)0x0) {
    FUN_00402eac((int *)piVar2[0x24]);
  }
  FUN_00402eac((int *)piVar2[0x27]);
  FUN_00402eac((int *)piVar2[0x2a]);
  FUN_0042fab4(piVar2,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar2);
  }
  return;
}

