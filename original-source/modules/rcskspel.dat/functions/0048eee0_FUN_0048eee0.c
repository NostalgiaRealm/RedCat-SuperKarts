/*
 * FUN_0048eee0 at 0048eee0
 * undefined FUN_0048eee0(void)
 * Address ranges: 0048eee0-0048ef6f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void __fastcall FUN_0048eee0(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piStack_28;
  int *piStack_20;
  undefined4 *puStack_1c;
  int *piStack_18;
  undefined1 *puStack_14;
  undefined1 local_c [12];
  
  puStack_14 = (undefined1 *)0x48eeeb;
  cVar1 = FUN_0048ebc0();
  if (cVar1 != '\0') {
    puStack_1c = *(undefined4 **)(param_1 + 4);
    puStack_14 = local_c;
    piStack_18 = (int *)&DAT_004d3480;
    piStack_20 = (int *)0x48ef01;
    iVar2 = (**(code **)*puStack_1c)();
    if (-1 < iVar2) {
      piStack_20 = piStack_18;
      (**(code **)(*piStack_18 + 0x20))();
      piStack_28 = (int *)&DAT_004d3490;
      iVar2 = (**(code **)**(undefined4 **)(param_1 + 4))(*(undefined4 **)(param_1 + 4));
      if (-1 < iVar2) {
        piVar3 = (int *)0x0;
        (*(code *)piStack_18[8])(&piStack_18,0);
        (**(code **)(*piVar3 + 8))(piVar3);
      }
      piVar3 = (int *)0xffffffff;
      (*pcRam56a868da)(&DAT_004d3490,0xffffffff,&piStack_20);
      (**(code **)(*piVar3 + 0x24))(piVar3);
      (**(code **)(*piStack_28 + 8))(piStack_28);
      FUN_0048ec10(1);
    }
  }
  return;
}

