/*
 * FUN_00408a70 at 00408a70
 * undefined __register FUN_00408a70(int * param_1, byte * param_2, undefined4 param_3, undefined4 param_4)
 * Address ranges: 00408a70-00408b37
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Removing unreachable block (ram,0x00408a9a) */

void FUN_00408a70(int *param_1,byte *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  byte local_100e [10];
  int *piStack_1004;
  undefined4 local_c;
  byte *local_8;
  
  piStack_1004 = param_1;
  local_c = param_3;
  local_8 = param_2;
  iVar1 = FUN_00403dd0((int)param_2);
  if (iVar1 < 0xc02) {
    iVar1 = FUN_00403dd0((int)local_8);
    uVar2 = FUN_004085fc(local_100e,(byte *)0x1001,local_8,param_4,local_c,iVar1);
    uVar3 = 0x1002;
  }
  else {
    uVar2 = FUN_00403dd0((int)local_8);
    uVar3 = uVar2;
  }
  if ((int)uVar2 < (int)(uVar3 - 1)) {
    FUN_00403c38(param_1,(undefined4 *)local_100e,uVar2);
  }
  else {
    while ((int)(uVar3 - 1) <= (int)uVar2) {
      uVar3 = uVar3 * 2;
      FUN_00403b50(param_1);
      FUN_00404104(param_1,uVar3);
      iVar1 = FUN_00403dd0((int)local_8);
      uVar2 = FUN_004085fc((byte *)*param_1,(byte *)(uVar3 - 1),local_8,param_4,local_c,iVar1);
    }
    FUN_00404104(param_1,uVar2);
  }
  return;
}

