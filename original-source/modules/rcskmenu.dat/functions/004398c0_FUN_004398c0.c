/*
 * FUN_004398c0 at 004398c0
 * undefined4 __register FUN_004398c0(int * param_1)
 * Address ranges: 004398c0-00439941
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004398c0(int *param_1)

{
  HMENU pHVar1;
  char *pcVar2;
  int iVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined1 *puVar4;
  char local_204 [512];
  
  puVar4 = &stack0xfffffffc;
  local_204[0] = '\0';
  if (param_1[0xb] != 0) {
    pHVar1 = (HMENU)(**(code **)(*param_1 + 0x34))();
    FUN_00439820(pHVar1,extraout_EDX,extraout_ECX,(int)puVar4);
  }
  if (param_1[0xc] != 0) {
    pcVar2 = FUN_00403f94((undefined *)param_1[0xc]);
    iVar3 = FUN_00408448(pcVar2,local_204);
    if (iVar3 == 0) {
      return 0;
    }
  }
  FUN_00403d80(param_1 + 0xc,local_204,0x200);
  return 1;
}

