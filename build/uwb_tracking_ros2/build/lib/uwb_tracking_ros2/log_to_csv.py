import os
import csv
from datetime import datetime

class CsvLogger:
    def __init__(self):
        self.filename = None

    def log_raw(self, raw_string):
        if self.filename is None:
            log_dir = os.path.join(os.getcwd(), "uwb_raw_data")
            os.makedirs(log_dir, exist_ok=True)
            
            self.filename = os.path.join(log_dir, datetime.now().strftime("uwb_raw_%d_%H%M.csv"))
            
            # Ghi Header
            with open(self.filename, mode='w', newline='') as f:
                csv.writer(f).writerow(['data'])

        with open(self.filename, mode='a', newline='') as f:
            csv.writer(f).writerow([raw_string])
            

