/*
 * FUN_0048ee60 at 0048ee60
 * undefined FUN_0048ee60(void)
 * Address ranges: 0048ee60-0048eed4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void __fastcall FUN_0048ee60(int param_1)

{
  char cVar1;
  int iVar2;
  int *piStack_18;
  int *piStack_14;
  undefined1 *puStack_10;
  undefined1 local_8 [8];
  
  puStack_10 = (undefined1 *)0x48ee6b;
  cVar1 = FUN_0048ebc0();
  if (cVar1 != '\0') {
    piStack_18 = *(int **)(param_1 + 4);
    puStack_10 = local_8;
    piStack_14 = (int *)&DAT_004d3480;
    iVar2 = (**(code **)*piStack_18)();
    if (-1 < iVar2) {
      (**(code **)(*piStack_14 + 0x24))(piStack_14);
      (**(code **)(*piStack_18 + 8))(piStack_18);
      iVar2 = (**(code **)**(undefined4 **)(param_1 + 4))
                        (*(undefined4 **)(param_1 + 4),&DAT_004d3490);
      if (-1 < iVar2) {
        (*(code *)piStack_18[8])(&piStack_18,0);
        (**(code **)(iRam00000000 + 8))(0);
        FUN_0048ec10(1);
      }
    }
  }
  return;
}

