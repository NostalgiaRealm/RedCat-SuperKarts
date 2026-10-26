/*
 * FUN_00419370 at 00419370
 * undefined FUN_00419370(void)
 * Address ranges: 00419370-00419470
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00419370(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0x28;
  iVar3 = 0;
  FUN_004b1850(0,0,0x28,&DAT_004e187c);
  iVar1 = FUN_004b3830(0x20);
  while( true ) {
    if (iVar1 != 0) {
      FUN_00419230(0x20);
      return iVar3;
    }
    iVar1 = FUN_004b3830(0x26);
    if (iVar1 != 0) {
      FUN_004b1850(0,0,iVar2,&DAT_004e1880);
      iVar3 = iVar3 + -1;
      iVar2 = iVar2 + -0x14;
      if (iVar3 < 0) {
        iVar3 = param_1 + -1;
        iVar2 = (iVar3 * 5 + 10) * 4;
      }
      FUN_004b1850(0,0,iVar2,&DAT_004e1884);
      FUN_00419230(0x26);
    }
    iVar1 = FUN_004b3830(0x28);
    if (iVar1 != 0) {
      FUN_004b1850(0,0,iVar2,&DAT_004e1888);
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x14;
      if (param_1 <= iVar3) {
        iVar3 = 0;
        iVar2 = 0x28;
      }
      FUN_004b1850(0,0,iVar2,&DAT_004e188c);
      FUN_00419230(0x28);
    }
    iVar1 = FUN_004b3830(0x1b);
    if (iVar1 != 0) break;
    iVar1 = FUN_004b3830(0x20);
  }
  FUN_00419230(0x1b);
  return -1;
}

