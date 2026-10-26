/*
 * FUN_00432644 at 00432644
 * undefined __register FUN_00432644(int param_1, int param_2)
 * Address ranges: 00432644-004326fe
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00432644(int param_1,int param_2)

{
  char *pcVar1;
  LPCSTR pCVar2;
  LPCSTR pCVar3;
  UINT *in_FS_OFFSET;
  undefined1 uVar4;
  undefined1 uVar5;
  UINT UVar6;
  UINT UStack_120;
  undefined1 *puStack_11c;
  undefined1 *puStack_118;
  undefined *local_10c;
  byte local_108 [256];
  undefined *local_8;
  
  puStack_118 = &stack0xfffffffc;
  local_10c = (undefined *)0x0;
  local_8 = (undefined *)0x0;
  puStack_11c = &LAB_004326ff;
  UStack_120 = *in_FS_OFFSET;
  *in_FS_OFFSET = (UINT)&UStack_120;
  FUN_00403be8((int *)&local_8,*(int *)(param_2 + 4));
  uVar4 = 0;
  uVar5 = local_8 == (undefined *)0x0;
  if (!(bool)uVar5) {
    pcVar1 = FUN_00408144(local_8);
    FUN_00402c58((char *)local_108,pcVar1);
    FUN_00402a60(local_108,&DAT_0043270c);
    if (!(bool)uVar4 && !(bool)uVar5) {
      FUN_00403dd8((int *)&local_8,(undefined4 *)&LAB_00432718);
    }
  }
  UVar6 = 0x10;
  FUN_00431eb8(param_1,(int *)&local_10c);
  pCVar2 = FUN_00403f94(local_10c);
  pCVar3 = FUN_00403f94(local_8);
  FUN_004324ec(param_1,pCVar3,pCVar2,UVar6);
  *in_FS_OFFSET = UVar6;
  puStack_11c = &LAB_00432706;
  UStack_120 = 0x4326f6;
  FUN_00403b50((int *)&local_10c);
  UStack_120 = 0x4326fe;
  FUN_00403b50((int *)&local_8);
  return;
}

