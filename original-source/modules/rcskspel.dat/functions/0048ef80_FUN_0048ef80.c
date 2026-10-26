/*
 * FUN_0048ef80 at 0048ef80
 * undefined FUN_0048ef80(void)
 * Address ranges: 0048ef80-0048f007
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0048ef80(int param_1)

{
  int iVar1;
  undefined1 **ppuVar2;
  undefined1 *puVar3;
  undefined1 *puStack_18;
  undefined1 local_10 [16];
  
  puStack_18 = local_10;
  iVar1 = (**(code **)**(undefined4 **)(param_1 + 4))(*(undefined4 **)(param_1 + 4));
  if (-1 < iVar1) {
    puVar3 = local_10;
    ppuVar2 = &puStack_18;
    iVar1 = (*pcRam56a868d6)(&DAT_004d3450,ppuVar2,puVar3,&stack0xffffffec,0);
    if (-1 < iVar1) {
      if (puVar3 == (undefined1 *)0x1) {
        FUN_0048eee0();
        if (*(char *)(param_1 + 0xc) != '\0') {
          FUN_0048edc0();
          (**(code **)(*ppuVar2 + 8))(ppuVar2);
          return;
        }
      }
      else if ((puVar3 == (undefined1 *)0x2) || (puVar3 == (undefined1 *)0x3)) {
        FUN_0048ee60();
      }
    }
    (**(code **)(*ppuVar2 + 8))(ppuVar2);
  }
  return;
}

