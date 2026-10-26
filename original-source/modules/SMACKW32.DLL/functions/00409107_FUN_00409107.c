/*
 * FUN_00409107 at 00409107
 * undefined __fastcall FUN_00409107(undefined4 param_1, undefined4 param_2)
 * Address ranges: 00409107-00409150
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00409107(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int extraout_ECX;
  undefined4 *extraout_EDX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  (*(code *)PTR_FUN_0040ef70)(param_2,param_1);
  puVar1 = DAT_00410a4c;
  puVar3 = &DAT_00410a4c;
  do {
    puVar2 = puVar1;
    if (puVar2 == (undefined4 *)0x0) {
LAB_00409147:
      (*(code *)PTR_FUN_0040ef74)();
      return;
    }
    if (extraout_ECX == puVar2[1]) {
      if (puVar2[3] != 0) {
        FUN_0040650f();
        puVar2 = extraout_EDX;
      }
      *puVar3 = *puVar2;
      FUN_0040650f();
      goto LAB_00409147;
    }
    puVar1 = (undefined4 *)*puVar2;
    puVar3 = puVar2;
  } while( true );
}

