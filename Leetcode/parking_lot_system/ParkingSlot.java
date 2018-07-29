public class ParkingSlot {

  private String slotId;
  private String slotNumber;
  private ParkingStatus status;
  private SlotSize slotSize;
  private Vehicle vehicle;

  public ParkingSlot(String slotId, String slotNumber, ParkingStatus status, SlotSize slotsize){
    this.slotId = slotId;
    this.slotNumber = slotNumber;
    this.status = status;
    this.slotSize = slotSize;
  }

  public void parkVehicle(Vehicle vehicle){
    if(this.slotsize.isVehicleParkingPossible(vehicle)) {
      this.vehicle = vehicle;
      status = ParkingStatus.OCCUPIED;
    }
    else {
      throw new IllegalArgumentException("Parking not possible");
    }
  }


