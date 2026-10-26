/*
 * FUN_004361d4 at 004361d4
 * undefined FUN_004361d4(void)
 * Address ranges: 004361d4-00436286
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004361d4(int *param_1,char param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  byte extraout_DL;
  
  piVar1 = FUN_0040320c(param_1,param_2);
  FUN_0043a7e8(DAT_0047d79c,(int)piVar1);
  if ((int *)piVar1[0x16] != (int *)0x0) {
    FUN_004383d4((int *)piVar1[0x16],(int)piVar1);
    piVar1[0x16] = 0;
  }
  while( true ) {
    iVar3 = FUN_00438084((int)piVar1);
    if (iVar3 < 1) break;
    piVar2 = (int *)FUN_00438094((int)piVar1,0);
    FUN_00402eac(piVar2);
  }
  if (piVar1[10] != 0) {
    FUN_004365f0(piVar1,0);
    DestroyMenu((HMENU)piVar1[10]);
  }
  FUN_00402eac((int *)piVar1[0x14]);
  FUN_0040bfec(piVar1 + 0xe);
  FUN_0040bfec(piVar1 + 0x1b);
  if (*(ushort *)(piVar1 + 0x11) != 0) {
    FUN_0040fbd8(DAT_0047d7a4,(uint)*(ushort *)(piVar1 + 0x11),'\0');
  }
  if ((int *)piVar1[0x10] != (int *)0x0) {
    FUN_00402eac((int *)piVar1[0x10]);
  }
  FUN_004147c4(piVar1,extraout_DL & 0xfc);
  if ('\0' < (char)extraout_DL) {
    FUN_004031fc(piVar1);
  }
  return;
}

